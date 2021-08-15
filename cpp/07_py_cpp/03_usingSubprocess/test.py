import subprocess
import os

os.system("g++ main.cpp")
print("write:")
# p1 = subprocess.run("./a.out", capture_output=True, text=True)

# p1 = subprocess.run("./a.out", stdout=subprocess.PIPE, text=True)
# print("Got input from cpp: ", p1.stdout)


p1 = subprocess.Popen("./a.out", stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
p1.wait()
out, err = p1.communicate()
print("Got input from cpp: ", out)






























# subprocess.call(['ls', '-l'], shell=True)

# output = subprocess.check_output(['ls', '-1'])
# print("Bytes in output: ", len(output))
# print(output)



