.model small
.stack 100h
.data 
    CR equ 0dh
    LF equ 0ah
    success_msg db LF,CR,"Correctly Bracketed",LF,CR,'$'
    fail_msg db LF,CR,"Incorrectly Bracketed$",LF,CR,'$'
.code 
main proc
    ; init data segment
    mov ax,@data
    mov ds,ax

    mov ax,'&'
    push ax
start_:
    xor bx,bx ; clear bx
    mov ah,1
    int 21h
    cmp al,0dh
    je final_check_
    cmp al,'['
    je bracket_
    cmp al,'{'
    je bracket_
    cmp al,'('
    je bracket_
    cmp al,']'
    je square_
    cmp al,'}'
    je curly_
    cmp al,')'
    je paren_
    push bx
    jmp start_
bracket_:
    or bl,al
    push bx
    jmp start_
square_:
    pop dx
    cmp dl,'['
    je start_
    jne wrong_
curly_:
    pop dx
    cmp dl,'{'
    je start_
    jne wrong_
paren_:
    pop dx
    cmp dl,'('
    je start_
    jne wrong_
final_check_:
    pop dx
    cmp dl,'&'
    je ok_
    jne wrong_
ok_:
    ; print success msg
    lea dx,success_msg
    mov ah,9
    int 21h
    jmp exit_
wrong_:
    ; print failure msg
    lea dx,fail_msg
    mov ah,9
    int 21h
exit_:
    mov ah,4ch 
    int 21h
main endp
end main
