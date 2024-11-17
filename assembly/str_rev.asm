.model small
.stack 100h
.code 
main proc
    mov ax,'&'
    push ax
start_:
    xor bx,bx ; clear bx
    mov ah,1
    int 21h
    cmp al,0dh
    je newline_
    or bl,al
    push bx
    jmp start_
newline_:
    mov ah,2
    mov dl,0ah 
    int 21h
    mov ah,2
    mov dl,0dh 
    int 21h
reverse_:
    pop dx
    cmp dl,'&'
    je exit_
    mov ah,2
    int 21h
    jmp reverse_
exit_:
    mov ah,4ch 
    int 21h
main endp
end main
