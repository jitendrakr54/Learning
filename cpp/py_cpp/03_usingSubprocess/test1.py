import subprocess
import os

data, temp = os.pipe()
  
# write to STDIN as a byte object(convert string
# to bytes with encoding utf8)
os.write(temp, bytes("5 10\n", "utf-8"));
os.close(temp)

# store output of the program as a byte string in s
s = subprocess.check_output("g++ main1.cpp -o out2;./out2", stdin = data, shell = True)

# decode s to a normal string
print(s.decode("utf-8"))