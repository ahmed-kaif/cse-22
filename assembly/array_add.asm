.model small
.stack 100h
.data 
    twoD1 db 3 DUP(3 DUP (?))
    twoD2 db 3 DUP(3 DUP (?))
    sum db 3 DUP(3 DUP (?))
    result db 0
.code 
main proc
    ; chodur code starts here
    mov ax,@data
    mov ds,ax

    mov ch,0 ; i

    mov ah,1
    xor bx,bx
LP1:
    mov cl,0 ; j
    LP2:    
        LP3:
            mov ah,1
            int 21h
            cmp al,13
            je insert
            sub al,48   ; '0'
            mov cl,al

            mov al,result
            mov bl,10
            mul bl
            add al,cl
            mov result,al
            jmp LP3
    insert:
        mov dh,0
        mov dl,cl
        mov si,dx 
        mov al,result
        mov twoD1[bx][si],al
        
        inc cl
        cmp cl,2
        jle LP2 
    add bx,3
    inc ch
    cmp ch,2
    jle LP1

    ; reset ch,bx
    mov ch,0 ; i

    mov ah,1
    xor bx,bx
    mov result,0
LP4:
    mov cl,0 ; j
    LP5: 
        LP6:
            mov ah,1
            int 21h
            cmp al,13
            je insert_2
            sub al,48
            mov cl,al

            mov al,result
            mov bl,10
            mul bl
            add al,cl
            mov result,al
            jmp LP6
    insert_2:    
        mov dh,0
        mov dl,cl
        mov si,dx
        mov al,result
        mov twoD2[bx][si],al
        
        inc cl
        cmp cl,2
        jle LP5 
    add bx,3
    inc ch
    cmp ch,2
    jle LP4

    mov ah,2
LP7:
    mov cl,0 ; j
    LP8: 
        mov dh,0
        mov dl,cl
        mov si,dx
        mov dl,twoD2[bx][si]
        int 21h
        inc cl
        cmp cl,2
        jle LP8 
    add bx,3
    inc ch
    cmp ch,2
    jle LP7

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
