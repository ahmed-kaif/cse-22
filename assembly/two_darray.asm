.model small
.stack 100h
.data 
    twoD db 3 DUP(3 DUP (?))
.code 
main proc
    mov ax,@data
    mov ds,ax

    mov ch,0 ; i

    mov ah,1
    xor bx,bx
LP1:
    mov cl,0 ; j
    LP2:    
        int 21h
        mov dh,0
        mov dl,cl
        mov si,dx 
        mov twoD[bx][si],al
        
        inc cl
        cmp cl,2
        jle LP2 
    add bx,3
    inc ch
    cmp ch,2
    jle LP1

    mov bx,3
    mov si,1
    mov twoD[bx][si],al 

print_:
    mov ah,2
    mov dl,0ah
    int 21h
    mov dl,0dh
    int 21h
    mov dl,twoD[bx][si]
    int 21h
exit: 
    mov ah,4ch
    int 21h

main endp
    end main
