title copy a string to another one
.model small
.stack 100h
.data
    str1 db 'Hello'
    str2 db 5 dup(?)
.code
main proc
    mov ax,@data
    mov ds,ax 
    mov es,ax
    lea si,str1
    lea di,str2
    cld             ; clears DF
    mov cx,5        ; set the size to len(str1)
    rep movsb       ; repeat and move byte
display_str_:
    mov cx,5
    lea si,str2
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

