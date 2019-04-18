# Writeup CTF - Criptografia

Table of Contents
=================

   * [Writeup CTF - Criptografia](#writeup-ctf---criptografia)
      * [A cifra acompanhada de ovos](#a-cifra-acompanhada-de-ovos)
      * [It's all about the bass](#its-all-about-the-bass)
      * [The oldest trick in the book](#the-oldest-trick-in-the-book)
      * [Again and Again and Again](#again-and-again-and-again)
         * [Resolução alternativa](#resolução-alternativa)
      * [ASCII](#ascii)
      * [Francês](#francês)
         * [Cifra de Vigenère](#cifra-de-vigenère)
      * [Afim](#afim)
         * [A Cifra Afim](#a-cifra-afim)
      * [unLuckyNumber](#unluckynumber)

## A cifra acompanhada de ovos

Inicialmente, na descrição do arquivo:

```markdown
A senha deste desafio é um texto culinário ou não consegui enxergar algo em plena vista?

Coloque a resposta no formato Ganesh{flagAqui}


Créditos: IMEsec
```

Com um arquivo anexo com o seguinte texto:

```bash
PeoPlEHAVETheiRfAVORiTeKINDoFBAcONSOmeLIKEiTFaTtIERthANOTHERSSOmELiKEITCuTthICKeRORSMOKEdmUChOFYOURcHOICEISAbOUthoWYouAr
```

Parece estranho, é uma frase com várias letras maiúsculas e minúsculas falando algo sobre bacon.
Outra coisa relacionada a bacon é o nome do enunciado, afinal, ovos e bacon são um prato clássico.

Então, pesquisa-se sobre cifras de bacon, e encontra-se uma com exatamente esse nome, representada por grupos dos caracteres A e B.

O "insight" para resolver o desafio gira em torno de entender que existem formas diferentes de se representar caracteres A e B, por exemplo utilizando letras maiúsculas e minúsculas.

Tentando por exemplo substituir todas as letras maiúsculas por A's e minúsculas por B's e vice versa, basta jogar o resultado em decoders online como o [dcode.fr](dcode.fr), assim obtendo a flag, a qual deve ser colocada no formato Ganesh{}.

```
Ganesh{NAO_QUEIME_UMA_CIFRA_DE_BACON}
```

## It's all about the bass

É nos apresentado o enunciado:

```markdown
01000111 01100001 01101110 01100101 01110011 01101000 01111011 01110011 01101111 01011111 01111001 00110000 01110101 01011111 01100100
48 95 107 110 111 119 95 104
6F 77 5F 74 6F 5F 63 6F 6E
166 063 162 124 175 012 012
```



Com base no nome do desafio e na observação da sua descrição, percebemos que ele é dividido em 4 partes, sendo cada uma delas uma base numérica.

A primeira, a base binária, composta apenas por 0's e 1's, 

Convertendo, por exemplo, usando [esta](https://www.rapidtables.com/convert/number/ascii-hex-bin-dec-converter.html) ferramenta, temos a primeira parte da flag:

```bash
Ganesh{so_y0u_d
```



Continuando, com a mesma ferramenta, tomamos a segunda parte.
São caracteres entre 0 e 9, agrupados de forma a compor números entre 48 e 119.
Com tentamos a base decimal, então temos como segunda parte.

```bash
0_know_h
```



Para a terceira parte, com caracteres entre 5 e F, pressupomos ser a famosa base hexadecimal (ou 16).
Com o mesmo site:

```bash
ow_to_con
```

Para a quarta parte, temos caracteres entre 0 e 7, agrupados de 3 em 3.
Isso caracteriza a base octal. Para ela podemos usar a ferramenta [Cyberchef](https://gchq.github.io/CyberChef/)

```bash
v3rT}
```



Então, agrupando as 4 partes, temos a flag `Ganesh{so_y0u_d0_know_how_to_conv3rT}`



## The oldest trick in the book

Na descrição, temos:

```
Nhulzo{H_mhtvzh_jpmyh_klJhlzhy}
```



Pelo enunciado, e também pelo formato da flag, é de se esperar que seja alguma cifra de substituição simples.

Uma das mais famosas é a conhecida cifra de César:

Consiste em avancar cada letra da CE um número (n) no alfabeto
Exemplo 1:

Se n=3 e CE='ABC'
então:

```
A + 3 casas no alfabeto = D
B + 3 casas no alfabeto = E
C + 3 casas no alfabeto = F
ACD='DEF'
```

Como só existem 26 n’s possíveis, podemos fazer um brute-force e vermos qual é a resposta chave.
Exemplo 2:

2.1

```
CE='NGGNPXNGQNJA'
Por brute-force, vemos que n=13
Assim, CD='ATTACKATDAWN'
```

2.2 Agora, o caso do desafio em si

```
CE='Nhulzo{H_mhtvzh_jpmyh_klJhlzhy}'
Por brute-force, vemos que n=7
Assim, CD='Ganesh{A_famosa_cifra_deCaesar}'
```

Como podemos ver, ela não traduz algorismos que não estão no alfabeto, portanto, se a CE estiver no formato PalavraAleatoria{Varios_Algorismos}, a mensagem codificada tem forte chance de ter sido encriptografada com a Cifra de César.

Site recomendado: https://www.dcode.fr/caesar-cipher

## Again and Again and Again

O desafio envolve uma forma comum de codificação, que é a [base 64](https://en.wikipedia.org/wiki/Base64), reconhecida por exemplo através da percepção que existem caracteres maiúsculos e minúsculos, seguidos por um *padding* do caractere `=`.

Apesar disso, tentando decodificar com algum decoder online ou algo do gênero, aparentemente nada acontece.
Porém, caso seja percebido com calma, na verdade a cifra está diminuindo de tamanho, o que se dá por conta do funcionamento da decodificação desta base.

Fazendo o decode múltiplas vezes, eventualmente chegamos à flag:

`Ganesh{Ag4in_4nd_4Ga1n}`

### Resolução alternativa

Outra possível forma de resolver este desafio é usando python.
Por exemplo, usando a biblioteca `pwntools`, (lembrando que é necessário instalar com `pip install pwn`) 

```python
from pwn import *

msg = read('again_and_again.txt')

while(msg != ""):
    msg = b64d(msg)
    print msg
```

Que eventualmente vai imprimir a flag (antes de dar erro)

## ASCII

Temos na descrição

```
71971101011151041231151011129711497116101951161041019510111099111100105110103125
```

De acordo com o enunciado, esperamos que isso seja ascii, que é o nome da codificação dada para letras nos computadores, hoje em dia sendo apenas uma alternativa simples, usada quando não é necessário o grande uso de caracteres especiais (neste caso usa-se por exemplo Unicode)

Mas caso joguemos em algum [decoder](http://www.unit-conversion.info/texttools/ascii/), só vai dar várias linhas sem sentido

Caso olhemos uma [tabela ascii](https://web.fe.up.pt/~ee96100/projecto/Tabela%20ascii.htm), percebemos que os caracteres ASCII tem sua representação em decimal de 0 a 255, com caracteres "legíveis" começando aproximadamente à partir de 30, porém na linha do enunciado temos vários caracteres por exemplo 71... que estão no começo, assim torna-se necessário separá-los por um espaço da seguinte forma

```
071 097 110 101 115 104 123 115 101 112 097 114 097 116 101 095 116 104 101 095 101 110 099 111 100 105 110 103 125
```

Observe que foi utilizado o critério: Se é um caractere legível, separe em um grupo.
Jogando a linha acima no mesmo decoder comentado, temos a flag:

`Ganesh{separate_the_encoding}`

## Francês

Temos na descrição

```
Uma mensagem misteriosa aparece na sua janela:
UOEPLPZUXUJRVT
Hint: Turnebus disciple
```



Um francês famoso é Blaise de Vigènere, aquele cuja atribuição da cifra de Vigenere é dada (apesar dela ter sido inventada por outra pessoa), e é sobre isso que se trata o desafio:

### Cifra de Vigenère

Ela é baseada na Cifra de Ceaser e consiste em avancar determinada quantidades de casas no alfabeto (n) para cada letra a ser cifrada.
A Key determina o n para cada letra

```
Por exemplo, se a Key='ABC' e queremos cifrar a palavra 'OIE'
Vemos que A=0, B=1, C=2

Portanto O + 0 casas no alfabeto = O
         I +  1 casa no alfabeto = J
         E + 2 casas no alfabeto = G
Então 'OIE', com a Key='ABC' vira 'OJG'
```



Como precisamos da Key para descriptar, só vale a pena usar brute-force se soubermos que a Key é pequena.
OBS: Se Key<CE, A Key se repete para os próximos algorismos.
No desafio temos:

```
'UOEPLPZUXUJRVT'
Usando 'Turnebus' como Key, obtemos
CD='BUNCHOFCEASERS'
(Se não tivessemos conseguido, tentariamos Key='disciple')
```

Que é a flag:

`Ganesh{BUNCHOFCEASERS}`

Site recomendado: https://www.cs.du.edu/~snarayan/crypt/vigenere.html



## Afim

Temos a descrição

```
Você estava andando pela USP quando um papel voa na sua cara, nele só estava escrito as seguintes letras:
TPBKYDREADYDJREW
```

### A Cifra Afim

Consiste em transformar cada letra do alfabeto em seu equivalente numérico, e após isso, usar uma função para achar um novo equivalente, o qual sera transformado denovo em uma letra do alfabeto.
A Função Afim tem o formato de y=ax+b, em que y=novo_equivalente, a=coeficiente1, x=antigo_equivalente e b=coeficiente 2.
OBS: Se y>26 (quantidade de letras no alfabeto). Se usa o resto da divisão por 26 como y.
Exemplo 1:

```
Se eu quiser encriptar 'ABC' usando a=5 b=7
Temos que:
A=0 -> y=5*0 + 7 = 7 -> 7=H
B=1 -> y=5*1 + 7 = 12 -> 12=M
C=2 -> y=5*2 + 7 = 17 -> 17=R
Portanto, 'ABC' vira 'HMR'
```

Como o número de soluções possíveis é 26*26=676, existem sites que fazem brute-force e retornam os resultados mais provaveis.
Tomando agora o enunciado do desafio	:

```
'TPBKYDREADYDJREW'
Por brute-force achamos que a=3 e b=17
Temos que CD='SIMPLEANDELEGANT'
```



Que é a flag do desafio:

`SIMPLEANDELEGANT`

## unLuckyNumber

Temos a descrição:

```
NGGNPXNGQNJA
```

Se você pensa em um número que dá azar, qual seria?
Provavelmente seria algo ligado ao 13... A famosa sexta feira 13 (dentre outras coisas)

Uma das cifras mais conhecidas no mundo é a ROT13, um caso específico da famosa cifra de césar, onde a rotação é em 13 caracteres.
Aplicando um decoder de Cesar em 13 caracteres, temos:

`ATTACKATDAWN`