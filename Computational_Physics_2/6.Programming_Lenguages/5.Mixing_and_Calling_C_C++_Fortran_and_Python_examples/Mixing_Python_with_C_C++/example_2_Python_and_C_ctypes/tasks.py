""" Task definitions for invoke command line utility for python bindings
    overview article.
"""
import cffi
import invoke
import pathlib
import sys
import os
import shutil
import re
import glob

on_win = sys.platform.startswith("win")


@invoke.task
def clean(c):
    """Remove any built objects"""
    for file_pattern in (
        "*.o",
        "*.so",
        "*.obj",
        "*.dll",
        "*.exp",
        "*.lib",
        "*.pyd",
        "cffi_example*",  # Is this a dir?
        "cython_wrapper.cpp",
    ):
        for file in glob.glob(file_pattern):
            os.remove(file)
    for dir_pattern in "Release":
        for dir in glob.glob(dir_pattern):
            shutil.rmtree(dir)


def print_banner(msg):
    print("==================================================")
    print("= {} ".format(msg))


@invoke.task()
def build_cmult(c, path=None):
    """Build the shared library for the sample C code"""
    # Moving this type hint into signature causes an error (???)
    c: invoke.Context
    if on_win:
        if not path:
            print("Path is missing")
        else:
            # Using c.cd didn't work with paths that have spaces :/
            path = f'"{path}vcvars32.bat" x86'  # Enter the VS venv
            path += f'&& cd "{os.getcwd()}"'  # Change to current dir
            path += "&& cl /LD cmult.c"  # Compile
            # Uncomment line below, to suppress stdout
            # path = path.replace("&&", " >nul &&") + " >nul"
            c.run(path)
    else:
        print_banner("Building C Library")
        cmd = "gcc -c -Wall -Werror -fpic cmult.c -I /usr/include/python3.8"
        invoke.run(cmd)
        invoke.run("gcc -shared -o libcmult.so cmult.o")
        print("* Complete")


@invoke.task()
def test_ctypes(c):
    """Run the script to test ctypes"""
    print_banner("Testing ctypes Module for C")
    # pty and python3 didn't work for me (win).
    if on_win:
        invoke.run("python ctypes_c_test.py")
    else:
        invoke.run("python3 ctypes_c_test.py", pty=True)


@invoke.task(
    clean,
    build_cmult,
    test_ctypes,

)
def all(c):
    """Build and run all tests"""
    pass
