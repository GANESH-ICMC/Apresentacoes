import os

MSGS = ("mensagem 1",\
        "mensagem 2",\
        "mensagem 3",\
        "mensagem 4",\
        "mensagem 5",\
        "mensagem 6",\
        "mensagem 7",\
        "mensagem 8",\
        "mensagem 9",\
        "mensagem 10")

def bytexor(a, b):
    return bytes(x^y for x, y in zip(a, b))

def random(size=16):
    return os.urandom(size)

def encrypt(key, msg):
    msg = bytes(msg, 'ascii')
    c = bytexor(key, msg)
    print(c.hex())
    return c

key = random(max(len(msg) for msg in MSGS))
ciphertexts = [encrypt(key, msg) for msg in MSGS]
