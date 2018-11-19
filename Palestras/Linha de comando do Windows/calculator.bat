::https://github.com/Gowq
@echo off



:START 
cls 

set /p number1=First number: 

set /p number2=Second number: 

set /p math=Options avaliable are: add, sub, mult or div: 

IF '%math%' == 'add' GOTO ADD

IF '%math%' == 'sub' GOTO SUB

IF '%math%' == 'mult' GOTO MULT
IF '%math%' == 'div' GOTO DIV
echo NOT FOUND
exit



:ADD

cls

Set /a result = %number1% + %number2%

echo The answer is %result%.

pause>nul
goto START



:SUB

cls

Set /a result = %number1% - %number2%

echo The answer is %result%.

pause>nul

goto START



:MULT
cls

Set /a result = %number1% * %number2%

echo The answer is %result%.

pause>nul

goto START



:DIV

cls

Set /a result = %number1% / %number2%

echo The answer is %result%.

pause>nul

goto START
