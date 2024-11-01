import os
from setuptools import setup, Extension

# directory where BOOST is installed
boost_dir = '/usr/local/'
if os.environ.get('BOOST_DIR'):
    boost_dir = os.environ.get('BOOST_DIR')
elif os.environ.get('EBROOTBOOST'):
    boost_dir = os.environ.get('EBROOTBOOST')

setup(
    name='scatter',
    description='A python code that computes the wave scattered by an obstacle',
    license='BSD',
    scripts=['scatter.py'],
    ext_modules=[Extension('wave', ['src/wave.cpp'],
                           include_dirs=[boost_dir + '/include'],
                           library_dirs=[boost_dir + '/lib'],
                           libraries=['boost_math_tr1'],
                           runtime_library_dirs = [boost_dir + '/lib'],
                           )],
)
