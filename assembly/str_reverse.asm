title string reverse without stack 
.model small
.stack 100h
.data
    str1 db "HELLO"
    str2 db  5 dup(?)
.code
main proc
    mov ax,@data
    mov ds,ax 
    mov es,ax

    lea si,str1+4   ; str1 + 4 = end of the str1
    lea di,str2     ; points to start of str2
    
    std             ; rtl processing
    mov cx,5
move_:
    movsb           ; here 'rep movsb' won't work as std was used
    add di,2        ; movsb decrements si and di as DF = 1 so we must adjust
    loop move_  
    
display_str_:
    mov cx,5
    lea si,str2
    cld
    mov ah,2
print_:
    lodsb
    mov dl,al 
    int 21h
    loop print_

    mov ah,4ch
    int 21h
main endp
end main

