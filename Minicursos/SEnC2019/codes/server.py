#! /usr/bin/python

import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('localhost',8888))
server.listen(5)

count = 0

while True:
    conn, addr = server.accept()
    buf = conn.recv(64)
    with open(str(count) + '.png','wb') as f:
        while(len(buf) == 64):
            f.write(buf)
            buf = conn.recv(64)
        if(buf):
            f.write(buf)
    count += 1
