bits 64
global _start
section .text

_start:
    push 0x646e7770; ‘dnwp’
    mov rax, 1 ; write
    mov rdi, 1
    mov rsi, rsp
    mov rdx, 4
    syscall

    mov rax, 60 ; exit
    mov rdi, 0
    syscall

