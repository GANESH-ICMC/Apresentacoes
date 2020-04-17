import operator

def calculaFrequencias(mensagem, tamBloco):
    frequencia = {}
    for i in range(len(mensagem)-tamBloco+1):
        if ' ' not in (mensagem[i:i+tamBloco]):
            bloco = mensagem[i:i+tamBloco]
            if bloco in frequencia:
                frequencia[bloco] += 1
            else:
                frequencia[bloco] = 1
    return frequencia

# mensagem que se deseja analisar a frequência
mensagem = ""

frequencias = list()

# obtem as frequências de blocos de tamanho 2 até 4, inclusos
for i in range(2, 5):
    f = calculaFrequencias(mensagem, i).items()
    frequencias += list(f)

# ordena pelo valor da frequência
freq_ord = sorted(frequencias, key=operator.itemgetter(1), reverse=True)

# limite de frequências abaixo da qual elas não serão mostradas na tela
limite = 5

print("Simbolo(s) | Frequência")
for letra, freq in freq_ord:
    if freq > limite:
        print(letra.center(10, ' '), str(freq).center(11, ' '))

