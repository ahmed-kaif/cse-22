.model small
.stack 100h
.data
    LF equ 0ah
    CR equ 0dh
    input_msg db LF,CR,"Enter number: $"
.code 
main proc
    ; init data segment
    mov ax,@data
    mov ds,ax

    mov ax,'&'
    push ax

    lea dx,input_msg
    mov ah,9
    int 21h
    xor cx,cx ; clear cx
    mov ah,1
    int 21h

    sub al,'0'
    or cl,al    ; cx = input value
    mov ax,1    ; prod = 1
start_:
    mul cx  ; DX:AX = CX * AX
    loop start_
reverse_:
    mov bx,10
    mov dx,0   ; clear dx before dividing dx:ax
    cmp ax,0
    je newline_
    div bx      ; quo -> AX , rem -> DX
    push dx
    jmp reverse_
newline_:
     mov ah,2
     mov dl,0ah 
     int 21h
     mov ah,2
     mov dl,0dh 
     int 21h
print_:
    pop dx
    cmp dx,'&'
    je exit_
    add dl,30h
    mov ah,2 
    int 21h
    jmp print_
exit_:
    mov ah,4ch 
    int 21h
main endp
end main
