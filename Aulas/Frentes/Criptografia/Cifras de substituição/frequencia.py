from collections import defaultdict

def calculaFrequencias(mensagem, tamBloco):
    frequencia = defaultdict(int)
    blocos = (mensagem[i:i+tamBloco] for i in range(len(mensagem) - tamBloco + 1))
    for bloco in blocos:
        if ' ' not in bloco:
            frequencia[bloco] += 1
    return frequencia

# mensagem que se deseja analisar a frequência
mensagem = ""

frequencias = list()

# obtem as frequências de blocos de tamanho 2 até 4, inclusos
for tamBloco in range(2, 5):
    f = calculaFrequencias(mensagem, tamBloco).items()
    frequencias += f

# ordena pelo valor da frequência
freq_ord = sorted(frequencias, key=lambda item: item[1], reverse=True)

# limite de frequências abaixo da qual elas não serão mostradas na tela
limite = 5

print("Simbolo(s) | Frequência")
for letra, freq in freq_ord:
    if freq > limite:
        print(letra.center(10, ' '), str(freq).center(11, ' '))

