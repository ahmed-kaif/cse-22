.model small
.stack 100h
.code       
main proc
    xor bx,bx
    mov cx,16
start_:
    mov ah,1 
    int 21h 
    cmp al,0dh
    je newline_
    and al,0fh  ; sub al,30h
    shl bx,1
    or bl,al
    jmp start_ 
newline_:
    mov ah,2
    mov dl,0ah
    int 21h
    mov dl,0dh
    int 21h
output_:
    mov ah,2
    shl bx,1
    jnc print_zero
    jc print_one
print_zero:
    mov dl,30h
    int 21h
    jmp label1
print_one:
    mov dl,31h
    int 21h
label1:
    loop output_
exit_:
    mov ah,4ch
    int 21h
main endp
    end main
