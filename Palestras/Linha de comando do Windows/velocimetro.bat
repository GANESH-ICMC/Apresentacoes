::https://github.com/Gowq
@echo on
msg * "Nao feche a janela, iremos avisar quando terminar"
::Minimizar
if not "%minimized%"=="" goto :minimized


 set minimized=true


start /min cmd /C "%~dpnx0"

goto :EOF


 :minimized
::


setlocal enabledelayedexpansion
for /f "tokens=3 delims=:" %%t in ('echo/%time%') do (
 for /f "tokens=1 delims=." %%v in ('echo/%%t') do (
  set /a segundos = %%v
 )
)
echo/Aguarde 1 minuto
set /a pontos=0
set /a segundoMaster = segundos
set /a umMinuto = segundos + 60
:loop
set /a pontos+=1
if !segundos! == !umMinuto! (
 cls
 msg * "!pontos!"
 pause>nul & exit
)

for /f "tokens=3 delims=:" %%t in ('echo/%time%') do (
 for /f "tokens=1 delims=." %%v in ('echo/%%t') do (
  set /a segundoAtual = %%v
  if !segundoAtual! NEQ !segundoMaster! ( 
   set /a segundoMaster = segundoAtual
   set /a segundos+=1
  )
 )
)
goto loop
