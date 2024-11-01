'''
https://www.quora.com/How-do-I-write-a-Python-script-to-run-a-C-program
'''
import subprocess 
subprocess.call(["g++", "hello_world.cpp"]) 
tmp=subprocess.call("./a.out") 
print "printing result" 
print tmp 
