section .data
    hello db "Hello, Holberton", 0
    format db "%s\n", 0

section .text
    extern printf
    global main

main:
    ; Print "Hello, Holberton" with a new line
    push rbp
    mov rdi, format
    mov rsi, hello
    call printf
    pop rbp

    ; Exit the program
    xor rdi, rdi          ; exit status 0
    mov rax, 60           ; syscall number for sys_exit
    syscall
