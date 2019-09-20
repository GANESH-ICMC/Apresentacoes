# deve existir, no mesmo diretório, um arquivo 'ciphertexts.txt' com os ciphertexts
# em hexadecimal separados por uma quebra de linha


# calcula a frequencia em que foram encontrados possíveis espaços em cada posição
# da string cipher1 xor cipher2
def encontraEspacos(cipher1, cipher2, frequencias):
    cipher1 = bytes.fromhex(cipher1)
    cipher2 = bytes.fromhex(cipher2)
    c1Xc2 = xorBytes(cipher1, cipher2).hex()
    for i in range(0, len(c1Xc2), 2):
        numAscii = int(c1Xc2[i:i+2], 16)
        if temEspaco(numAscii):
            frequencias[int(i/2)] += 1

def temEspaco(numAscii):
    if 65 <= numAscii <= 90 or\
            97 <= numAscii <= 122 or\
            numAscii == 0:
        return True
    else:
        return False

def xorBytes(msg1, msg2):
    return bytes(a^b for a, b in zip(msg1, msg2))

def calculaFrequencias(ciphertexts):
    tamanhos = (int(len(msg)/2) for msg in ciphertexts)
    frequencias = tuple([0]*tam for tam in tamanhos)
    for cipher1, freq in zip(ciphertexts, frequencias):
        for cipher2 in ciphertexts:
            if cipher1 != cipher2:
                encontraEspacos(cipher1, cipher2, freq)
    return frequencias

def calculaChave(ciphertexts, frequencias):
    tamChave = max(int(len(msg)/2) for msg in ciphertexts)
    chave = [None]*tamChave
    maximaFrequencia = [0]*tamChave
    for cipher, freqs in zip(ciphertexts, frequencias):
        cipher = bytes.fromhex(cipher)
        for pos, freq in zip(range(len(freqs)), freqs):
            limite = calculaLimite(ciphertexts, pos) - 1
            tolerancia = int(limite/4)
            if freq >= limite-tolerancia and freq > maximaFrequencia[pos]:
                maximaFrequencia[pos] = freq
                chave[pos] = cipher[pos]^ord(' ')
    return chave

# quantidade de mensagens que possuem tamanho maior do que pos (2*pos em hexa)
def calculaLimite(ciphertexts, pos):
    pos = 2*pos
    return sum(1 for msg in ciphertexts if len(msg) > pos)

def calculaPlaintext(ciphertext, chave):
    ciphertext = bytes.fromhex(ciphertext)
    plaintext = ""
    for a,b in zip(ciphertext, chave):
        if b != None:
            plaintext += chr(a^b)
        else:
            plaintext += "_"
    return plaintext

def calculaPlaintexts(ciphertexts, chave):
    plaintexts = []
    for msg in ciphertexts:
        plaintexts.append(calculaPlaintext(msg, chave))
    return plaintexts

def imprimePlaintexts(ciphertexts, chave):
    plaintexts = []
    for msg, i in zip(ciphertexts, range(len(ciphertexts))):
        plaintexts.append(calculaPlaintext(msg, chave))
        print("{}.".format(i), plaintexts[-1])
    return plaintexts

def imprimeLista(lista):
    for item, i in zip(lista, range(len(lista))):
        print("{}.".format(i), item)

def alteraChave(ciphertexts, chave, string, pos, msg):
    tam = len(string)
    for i in range(pos, pos+tam):
        chave[i] = ord(string[i-pos])^int(ciphertexts[msg][i*2:i*2+2], 16)

def leCiphertexts(arquivo):
    with open(arquivo) as f:
        ciphertexts = f.readlines()
    return ciphertexts

def main():
    ciphertexts = leCiphertexts('ciphertexts.txt')

    frequencias = calculaFrequencias(ciphertexts)

    chave = calculaChave(ciphertexts, frequencias)

    plaintexts = calculaPlaintexts(ciphertexts, chave)

    imprimeLista(plaintexts)

if __name__ == '__main__':
    main()

