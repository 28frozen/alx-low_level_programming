section .data
    msg db "Hello, Holberton!", 10
    len equ $ - msg

section .text
    global _start

_start:
    ; Write the string to the standard output (stdout)
    mov rax, 1            ; syscall number for sys_write
    mov rdi, 1            ; file descriptor 1 (stdout)
    mov rsi, msg          ; pointer to the message
    mov rdx, len          ; length of the message
    syscall

    ; Exit the program
    mov rax, 60           ; syscall number for sys_exit
    xor rdi, rdi          ; exit status 0
    syscall
