.model small
.stack 100h
.data 
    CR equ 0dh
    LF equ 0ah
    A db 1,8,2,3,7,4
    input_msg db "Enter a number: $"
    found_msg db CR,LF,"Found$"
    not_found_msg db CR,LF,"Not Found$"
.code
main proc
    mov ax,@data
    mov ds,ax
    mov cx,6
    xor bx,bx ; bx = 0
    xor ax,ax
input_:
    lea dx,input_msg
    mov ah,9
    int 21h
    mov ah,1
    int 21h
    sub al,'0'
start_:
    cmp A[bx],al
    je found_
    inc bx
    loop start_
    jmp not_found_
found_:      
    lea dx,found_msg
    mov ah,9
    int 21h
    jmp exit_
not_found_:
    lea dx,not_found_msg
    mov ah,9
    int 21h
exit_:
    mov ah,4ch 
    int 21h
main endp
    end main
    
