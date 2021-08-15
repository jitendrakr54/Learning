# from ctypes import *
# # libc = cdll.LoadLibrary("libtest.so")
# libc = CDLL("./libtest.so")

# libc.print()

import os

os.system("g++ main.cpp")   #compile c++ program
os.system("./a.out")        #launch executable

file1 = open("sample.txt", "r")
data = file1.read()
if data ==  "hello":
    print("Passed!")