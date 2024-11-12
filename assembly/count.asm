.MODEL small
.stack 100h
.code 
main proc
    mov bl,10001100b    ; bl = 1000 1100
    mov dl,0            ; init count = 0
    mov cl,8h           ; cl = 8
start_:
    dec cl
    shl bl,1            ; bl << 1
    jnc increment_
    cmp cl,0
    jz print_
increment_:
    add dl,1
    jmp start_
print_:
    mov ah,2
    add dl,30h
    int 21h
exit_:
    mov ah,4ch
    int 21h

main endp
    end main

