# Python

Table of Contents
=================

   * [Python](#python)
      * [Conceitos Básicos](#conceitos-básicos)
         * [Tipos de dados](#tipos-de-dados)
      * [Operações Básicas](#operações-básicas)
         * [Aritméticas](#aritméticas)
         * [Lógicas](#lógicas)
      * [Tipagem](#tipagem)
      * [Entrada e Saída](#entrada-e-saída)
      * [Listas](#listas)
      * [Strings](#strings)
      * [Controle](#controle)
         * [Condicionais](#condicionais)
         * [Repetição](#repetição)
      * [Bibliotecas](#bibliotecas)
         * [Import](#import)
         * [Pip](#pip)
         * [Biblioteca OS](#biblioteca-os)
         * [Biblioteca SYS](#biblioteca-sys)
         * [Pwntools](#pwntools)
            * [Utilities](#utilities)
            * [Tubes](#tubes)
               * [Conexão](#conexão)
               * [Envio e Recebimento de Informações](#envio-e-recebimento-de-informações)
               * [SSH](#ssh)
   * [References](#references)




## Conceitos Básicos

#### Tipos de dados:

​	A linguagem python tem tipos de dados definidos, apesar de não ser necessário específicá-los como em C, eles estão presentes "escondidos" no código.

```python
x = 5
y = 5.7
minhaString = "Olá Ganeshers!"
```



## Operações Básicas

### 	Aritméticas

​	Assim como em outras linguagens de programação, podemos realizar operações básicas de forma bem simples.

​	Soma, subtração e multiplicação agem como o esperado.
​	Divisão inteira não vira float!! 
​		Usando `//` temos divisão inteira
​	Potenciação é o símbolo `**`
​	Soma e multiplicação funcionam com strings

```python
x = 5; y = 7
x + y
y / x
y // x
str1 = "oi"; str2 = "estou aqui"
str1 + str2
str1 * x

```

### 	Lógicas

​		Usa-se `and` e `or` para as operações lógicas

​		Usa-se &, | e ^ para bitwise.
​			São feitas manipulações diretamente nos bits dos números, bit a bit
​			`&` 	-> `and`
​			`|` 	-> `or`
​			`^` 	-> `xor`

```python
1 and 0
1 and 1
0 or 1
0 or 0
6 & 3
6 | 3
6 ^ 3
```



## Tipagem

​	Um nome em python não precisa ficar preso ao mesmo tipo, mas python não permite misturar tipos

```python
x = 5
x = "Oi"
```



## Entrada e Saída

​	Lê-se usando a função `input()`, que é lida como uma string, então é necessário se fazer o *cast* para ler inteiros ou floats.

​	Imprime-se usando o print.
​		É possível alterar o separador e o final do que vai ser impresso pelo print. O caractere de fim de linha (`\n`) é colocado por padrão.
​		Pode-se ser utilizada uma "format string", assim como em C.

```python
print("Ola")
x = input()
y = 7
print("O valor de x é %d e y é %d" % (x, y) 
print("Sem o fim de linha", end="")
print("Com", "Espaços")
print("Mudando", "Separador", sep="_")

```



## Listas

​	É um conjunto ordenado de objetos que pode ter vários tipos.
​	Podemos inserir e remover elementos de qualquer posição.
​	O operador soma concatena duas listas

​	Métodos principais:
  - append - Coloca um elemento no fim da lista
  - count - Retorna a quantidade de vezes que um elemento aparece na lista
  - pop - Remove a posição dada
  - remove - Remove o elemento dado
  - index - Retorna o índice do primeiro elemento encontrado igual ao que se procura.

```python
myl = []
x = 5
myl.append(x)
myl.append("oi")
myl # imprime a lista myl
myl.count(x)
myl.remove(x)



```

## Strings

​	É um conjunto de caracteres.
​	No Python strings são imutáveis.

​	Métodos principais:

- len
- in
- split

```python
str1 = "Esta é uma string, estamos aqui na aula hoje"
len(str1)
l = str1.split(',')


```



## Controle

### Condicionais

​	São estruturas comuns, utilizadas para checar condições.
​	`if`, `elif` e `else`.

​	Não são usados parênteses e nem chaves, mas sim `:` e indentação.

```python
x = 5
if x > 3:
    print("X é maior que 3")
    print("Imprime novamente, mas só se maior que 3")
elif x < 0:
    print("X é negativo")
else:
    print("X é menor ou igual a 3")
    
print("Fim do programa")
```



### Repetição
 ​	Estruturas de while e for, funciona de forma semelhante ao C, com a atenção para a sintaxe do Python, ou seja, sem parêntesis e com `:` e indentação.

 ​	Usualmente o for é utilizado para iterar sobre uma lista, arquivo, set, etc; Mas pode ser usado também para iterar sobre um range de números

 ```python
 x = 5
 while x != 0:
     print(x)
     x -= 1 # x = x - 1
     
 for x in range(10):
     print(x)
     
 for animal in ["cachorro", "gato", "elefante"]:
    	print("%s é um animal" % (animal))
   
 ```



## Bibliotecas

### Import

​	`import` é o comando utilizado para usar bibliotecas em Python.

​	Para utilizar uma determinada função `func` de uma biblioteca `mylib`, utilizamos `mylib.func`.
​	É possível também usar um "nome" para uma biblioteca com `import mylib as minhabiblioteca`. 

### Pip

​	"Pip Installs Packages"

​	É o gerenciador de bibliotecas do Python, sendo utilizado para instalar novas bibliotecas para que possam ser utilizadas por imports.

### Biblioteca OS

​	Faz a interface com o sistema operacional, permitindo interagir com ele diretamente

​	Métodos importantes:

- os.system() - Executa um comando da shell
- os.uname() - Retorna informações sobre a máquina como versão do kernel, nome do sistema, etc.
- os.chdir(path) - Equivalente a utilizar o comando `ch` do linux para o `path`
- os.chmod(path, mode) - Equivalente a utilizar o comando `chmod` no arquivo especificado pelo path com o modo `mode`
- os.getcwd() - Retorna o diretório atual

```python
import os

os.uname()
os.uname().machine

os.getcwd()
os.chdir("..")
os.getcwd()

os.chmod("codes.py", 777)
os.chmod("codes.py", 644)

os.system("/bin/bash")
# para sair basta digitar exit ou apertar Ctrl + D

```

### Biblioteca SYS

​	Permite o acesso a objetos criados ou mantidos pelo interpretador Python

​	Os mais importantes são:

- sys.argv[] - Argumentos passados para o programa
- sys.exit([arg]) - Fecha o programa com possível mensagem de erro

Coloque o programa abaixo em um arquivo.
Utilize `chmod u+x nomeprograma.py` para que ele possa ser executado.
Execute com `./nomeprograma.py arg1 arg2 ...`

```python
#!/bin/python3

import sys

print(sys.argv)
if len(sys.argv) < 2:
    sys.exit("O programa crashou! Envie argumentos")

print("Chegou aqui")
```

### Pwntools

​	A biblioteca Pwntools foi feita com o intuito de facilitar a exploração de sistema. Ela tem vários módulos diferentes, que auxiliam desde a criptografia até conexões remotas.

​	É necessário instalar com o `pip install pwn`

​	OBS: A biblioteca é feita para Python2, caso o Python e o Pip padrão no seu sistema operacional sejam o 3, basta utilizar o pip2 e o Python2 para instalar e executar respectivamente.

#### Utilities

​	Funções utilitárias no geral, por exemplo para criptografia.

​	  Leitura e Escrita em arquivos

- read('filename') - Retorna o que está no arquivo todo

- write('filename', 'data') - Escreve os dados no arquivo

 
  Hashing e Encoding

- urlencode("Hello, World!") - Encoda a string para formato url
- enhex("hello") - Encoda a string em hex
- unhex("776f726c64") - Decoda a string hex
- b64e("Oi") - Encoda a string em base64
- b64d("b2k=") - Decoda a string de base64 para ascii

```python
from pwn import * # importa todas as funções para serem usadas diretamente, sem a necessidade de usar pwn.nomeFunção

b64e("Uma frase relativamente grande")
b64d("R2FuZXNoe3RoNG5rX3kwdV9mMHJfcjNhZDFuZ30=")

urlencode("Hello, World!")

enhex("hello") 
unhex("776f726c64")
```

#### Tubes

​	É um wrapper para entrada e saída de processos locais, conexões remotas (TCP e UDP), processos rodando remotamente, portas seriais, etc.

##### 	Conexão

​		Para processos remotos, conecta-se com o comando remote, o que vai retornar um objeto para input/output

```python
from pwn import *
io = remote("www.google.com")
```

##### 	Envio e Recebimento de Informações

​		Para enviar e receber informações por processos, é direto, utilizando os seguintes métodos:

​	Recebendo dados:

    	recv(n) - Recebe um número n de bytes disponíveis
    	recvline() - Recebe dados até que uma nova linha seja encontrada
    	recvuntil(delim) - Recebe dados até que um dado delimitador seja encontrado
    	clean() - Limpa todos os dados em buffer

​	Enviando dados:

    	send(data) - Envia dados
    	sendline(line) - Envia dados e uma nova linha (\n)
​	Exemplo de envio e recebimento de dados:

```python
from pwn import *

io = remote('google.com', 80)
io.send('GET /\r\n\r\n')
print(io.recvline())
# 'HTTP/1.0 200 OK\r\n'          
```





##### 	SSH

​		Para usar conexões ssh é bem direto também, basta utilizar o comando ssh

```python
from pwn import *

session = ssh('bandit0', 'bandit.labs.overthewire.org', password='bandit0')

io = session.process('sh', env={"PS1":""}) # transforma a sessão em uma shell.
io.sendline('echo Hello, world!')
io.recvline()
# 'Hello, world!\n'
```

# References

- [Violent Python - A Cookbook for Hackers ...](https://www.amazon.com.br/Violent-Python-Cookbook-Penetration-Engineers/dp/1597499579)
- [Black Hat Python](https://novatec.com.br/livros/black-hat-python/)
- [Pwntools Tutorial](https://github.com/Gallopsled/pwntools-tutorial )
- [Python3 Reference](https://docs.python.org/3/)
- [Pwntools Reference](http://docs.pwntools.com/en/stable/)

