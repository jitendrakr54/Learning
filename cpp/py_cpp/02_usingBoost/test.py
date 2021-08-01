import os
import hello_txt

os.system("make")
data = hello_txt.fun()

if data ==  "hello":
    print("Passed!")