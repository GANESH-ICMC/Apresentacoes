from os import urandom
from random import seed, shuffle
from typing import Iterable, Union

def xor(a: bytes, b: bytes) -> bytes:
    """ Xor byte a byte entre a e b """
    return bytes(x^y for x, y in zip(a, b))

def prg(tam:int, key:bytes) -> bytes:
    def ksa(key:bytes) -> list:
        S = [i for i in range(256)]
        j = 0
        for i in range(256):
            j = (j + S[i] + key[i % len(key)]) % 256
            S[i], S[j] = S[j], S[i]
        return S
    S = ksa(key)
    j = 0
    keystream = bytes()
    for i in range(tam):
        i = i % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        keystream += bytes([S[(S[i] + S[j]) % 256]])
    return keystream

def iv(tam: int) -> bytes:
    return urandom(tam)

def divide(mensagem: bytes, tam_bloco: int, encripta: bool = True) -> Iterable[bytes]:
    """ Retorna um Generator para blocos da 'mensagem' de tamanho 'tam_bloco' """
    tam_ultimo_bloco = len(mensagem)%tam_bloco
    if encripta:
        mensagem += bytes([tam_bloco-tam_ultimo_bloco]*(tam_bloco-tam_ultimo_bloco))
    qtd_blocos = len(mensagem)//tam_bloco
    blocos = (mensagem[bloco*tam_bloco:(bloco+1)*tam_bloco] for bloco in range(qtd_blocos))
    return blocos

def f(entrada: bytes, chave: bytes) -> bytes:
    ############# confusion #############
    saida = list(xor(entrada, chave))
    #####################################

    ############# diffusion #############
    soma = sum(byte for byte in chave)%256
    seed(soma)
    shuffle(saida)
    #####################################

    return bytes(saida)

def feistel_network(bloco: bytes, chaves: list) -> bytes:
    left = bloco[:len(bloco)//2]
    right = bloco[len(bloco)//2:]
    for chave in chaves:
        next_right = xor(left, f(right, chave))
        left = right
        right = next_right
    return (right + left)

def encripta_bloco(plainblock: bytes, iv: bytes, chaves: list) -> bytes:
    entrada = xor(plainblock, iv)
    cipherblock = feistel_network(entrada, chaves)
    return cipherblock

def decripta_bloco(cipherblock: bytes, iv: bytes, chaves: list) -> bytes:
    saida = feistel_network(cipherblock, chaves)
    plainblock = xor(saida, iv)
    return plainblock

def encripta(plaintext: str, chave: bytes, tam_bloco: int, qtd_rounds: int) -> bytes:
    if tam_bloco%2 != 0:
        raise ValueError('Tamanho do bloco deve ser par')
    plaintext = bytes(plaintext, 'utf-8')
    blocos = divide(plaintext, tam_bloco)
    iv = urandom(tam_bloco)
    tam_bloco //= 2
    # ignorando os 4 primeiros bytes do rc4
    keystream = prg(qtd_rounds*tam_bloco+4, chave)[4:]
    chaves = [keystream[round_*tam_bloco:(round_+1)*tam_bloco] for round_ in range(qtd_rounds)]
    ciphertext = iv
    for bloco in blocos:
        cipherblock = encripta_bloco(bloco, iv, chaves)
        iv = xor(bloco, cipherblock)
        ciphertext += cipherblock
    return ciphertext

def decripta(ciphertext: bytes, chave: bytes, tam_bloco: int, qtd_rounds: int) -> Union[str, bytes]:
    if tam_bloco%2 != 0:
        raise ValueError('Tamanho do bloco deve ser par')
    blocos = divide(ciphertext, tam_bloco, False)
    iv = next(blocos)
    tam_bloco //= 2
    # ignorando os 4 primeiros bytes do rc4
    keystream = prg(qtd_rounds*tam_bloco+4, chave)[4:]
    chaves = [keystream[round_*tam_bloco:(round_+1)*tam_bloco] for round_ in range(qtd_rounds)][-1::-1]
    plaintext = bytes()
    for bloco in blocos:
        plainblock = decripta_bloco(bloco, iv, chaves)
        iv = xor(bloco, plainblock)
        plaintext += plainblock
    n = plaintext[-1]
    end = -1*n
    try:
        return plaintext[:end].decode('utf-8')
    except UnicodeDecodeError:
        return plaintext[:end]

#cipher = encripta('From:Lucas\nTo:Lucas\nContent:criptografia de blocos', b'arroz', 10, 10)
#print(cipher)

###### ciphertext malandramente interceptado ######
#iv = bytearray(cipher[:10])
#iv[5:] = xor(iv[5:], xor(b'Lucas', b'Mario'))
#cipher = bytes(iv) + cipher[10:]
###################################################

#print()
#plain = decripta(cipher, b'arroz', 10, 10)
#print(plain)
