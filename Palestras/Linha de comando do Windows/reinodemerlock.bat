::https://github.com/Gowq
@echo off
color 0a
set "local=montanha"
set /a variavel10=%random% * 10/32768 + 1
cd %tmp%\reino_de_merlock\personagem
if exist ficha.txt (
  goto log) else (
    goto inicio)
:inicio
echo/msgbox "Não exclua a ficha do persongem nem a renomeie.", vbinformation, "">gua.vbs
wscript //nologo gua.vbs&del gua.vbs
echo Bem vindo ao Reino de Merlock
set /p "name=Qual o nome do seu personagem?: "
echo %name% >%tmp%\reino_de_merlock\personagem\ficha.txt
cls
echo No reino de merlock existem diversas tipos de criaturas, escolha um para seu campeao.
cd "%tmp%\Reino_de_merlock\Classes"
start personagens.docx 1>nul 2>nul&&goto classe
:classe
set /p "class=Qual a classe do seu personagem?: "
for %%l in (mago invocador elfo druida feiticeira bruxa anao gigante curandeiro sacerdote) do (
  CALL:VERIFICA %%l)
  echo/Classe nao reconhecida&pause>nul&goto classe
:VERIFICA
if %class%==%~1 (
  goto creator)
  exit/b
:creator
cd %tmp%\reino_de_merlock\classes
type %class%.txt >>"%tmp%\reino_de_merlock\personagem\ficha.txt
cd %tmp%\reino_de_merlock\classes\%class%
copy *.txt "%tmp%\reino_de_merlock\personagem\*.txt"
:montanha
cls
echo Bem vindo a motanha do desfiladeiro, para ver os comandos digite help
set "map=montanha"
set "esquerda=caverna"
set "reto2=3"
set "esquerda2=6"
set /p "run=Digite a acao: "
if %run%==andar_reto (
  goto reto)
  if %run%==help (
    goto help) else (
      goto comands)
:caverna
cls
echo Carvena
set "esquerda=abismo"
set "esquerda2=4"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:abismo
set "vida=0"
echo Você esta morto
taskkill /f /im cmd.exe
:reto
cls
set "esquerda=igreja"
set "direita=praia"
set "esquerda2=20"
set "direita2=15"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:praia
set "esquerda=vulcão"
set "direita=tuneis"
set "esquerda2=10"
set "direita2=15"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:igreja
set "direita=deserto"
set "direita2=15"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:deserto
set "direita=vulcão"
set "direita2=10"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:tuneis
set "esquerda=selva"
set "esquerda2=10"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:vulcão
set "direita=praia"
set "esquerda2=20"
set "direita2=15"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:selva
set "esquerda=reino"
set "esquerda2=25"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:reino
set "portal=inferno"
set /p "run=Digite a acao: "
if %run%==help (
  goto help) else (
    goto comands)
:comands
echo %run% >%tmp%\reino_de_merlock\personagem\comands.txt
cd %tmp%\reino_de_merlock\personagem
type comands.txt | find /i "map_exterior" && echo andar>map_2.txt
if exist map_2.txt (
  del /q map_2.txt
  cd %tmp%\reino_de_merlock\mundo
  start mundo_mapa.jpeg)
  type comands.txt | find /i "map_interior" && echo andar>map_1.txt
if exist map_1.txt (
  del /q map_1.txt
  cd "%tmp%\reino_de_merlock\mundo\%map%"
  start *.jpeg)
  type comands.txt | find /i "atacar" && echo andar>atacar.txt
if exist atacar.txt (
  del /q atacar.txt
  goto atacar)
  type comands.txt | find /i "defender" && echo andar>defender.txt
if exist defender.txt (
  del /q defender.txt
  goto defender)
  type comands.txt | find /i "esquivar" && echo andar>esquivar.txt
if exist esquivar.txt (
  del /q esquivar.txt
  goto esquivar)
  type comands.txt | find /i "inventario" && echo andar>inventario.txt
if exist inventario.txt (
  del /q inventario.txt
  goto inventario)
  type comands.txt | find /i "save" && echo andar>save.txt
if exist save.txt (
  del /q save.txt
  goto save)
  type comands.txt | find /i "andar_esquerda" && echo andar>andar_esquerda.txt
if exist andar_esquerda.txt (
  set "andar=esquerda1"
  del /q andar_esquerda.txt
  goto andar1)
  type comands.txt | find /i "andar_direita" && 1>nul echo andar>andar_direita.txt
if exist andar_direita.txt (
  set "andar=direita1"
  del /q andar_direita.txt
  goto andar1)
  type comands.txt | find /i "andar_reto" && echo andar>andar_reto.txt
if exist andar_reto.txt (
  set "andar=reto1"
  del /q andar_reto.txt
  goto andar1)
:atacar
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\inventario\arma\dano.txt"') do (
  set "dano=%%a")
  set /a mon_life=mon_life - dano
:defender
for /f %%a in ('type "%tmp%\reino_de_merlock\escudo\defesa.txt"') do (
  set "defesa=%%a")
  set /a mon_atk= mon_atk - defesa
  if %defesa% LSS 0 (
    set defesa=0)
:esquivar
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\esquiva.txt"') do (
  set "esquiva=%%a")
  if %esquiva% LSS %variavel% (
    set vida = mon_atk)
:inventario
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\inventario.txt"') do (
  set "inventario=%%a")
  echo inventario)
:andar1
if "%andar%" == "esquerda1" (
  goto andou)
if "%andar%" == "direita1" (
  goto andou1)
if %andar%==reto1 (
  goto andou2)
:andou
set /a andou = agilidade - esquerda2
if %andou% LEQ 0 (
  goto %esquerda%)
:andou1
set /a andou1 = agilidade - direita2
if %andou1% LEQ 0 (
  goto %direita%)
:andou2
set /a andou2 = agilidade - reto2
if %andou2% LEQ 0 (
  goto %reto%)
:log
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\hp.txt"') do (
  set "vida=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\aura.txt"') do (
  set "aura=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\forca.txt"') do (
  set "força=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\mira.txt"') do (
  set "mira=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\agilidade.txt"') do (
  set "agilidade=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\inteligencia.txt"') do (
  set "inteligencia=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\destreza.txt"') do (
  set "destreza=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\habilidade_com_armas.txt"') do (
  set "habilidade=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\resistencia.txt"') do (
  set "resistencia=%%a")
for /f %%a in ('type "%tmp%\reino_de_merlock\personagem\labia.txt"') do (
  set "labia=%%a")
goto %local%
:save
echo %vida%>>"%tmp%\reino_de_merlock\personagem\vida.txt"
echo %arma%>>"%tmp%\reino_de_merlock\personagem\inventario\arma\arma.txt"
echo %escudo%>>"%tmp%\reino_de_merlock\personagem\inventario\escudo.txt"
echo %elmo%>>"%tmp%\reino_de_merlock\personagem\inventario\elmo.txt"
echo %armadura%>>"%tmp%\reino_de_merlock\personagem\inventario\armadura.txt"
echo %artefato%>>"%tmp%\reino_de_merlock\personagem\inventario\artefato.txt"
echo %livro%>>"%tmp%\reino_de_merlock\personagem\inventario\livro.txt"
echo %aura%>>"%tmp%\reino_de_merlock\personagem\aura.txt"
echo %fome%>>"%tmp%\reino_de_merlock\personagem\fome.txt"
echo %status%>>"%tmp%\reino_de_merlock\personagem\inventario\status.txt"
echo %local%>>"%tmp%\reino_de_merlock\personagem\local.txt
:help
echo map_exterior - mostra o mapa da regiao que voce se encontra
echo map_interior - mostra o mapa de dentro da regiao que voce se encontra
echo atacar - ataca o mob com a arma que estiver em maos
echo defender - utiliza o escudo para se defender
echo esquivar - utiliza a agilidade para esquivar do ataque
echo inventario - abre o inventario
echo save - salva os status do jogo
echo andar_esquerda - vai para o caminho a esquerda
echo andar_direita - vai para o caminho a direita
echo andar_reto - vai para o caminho reto
pause>nul
goto %local%
