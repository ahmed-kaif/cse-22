title read string from console
.model small
.stack 100h
.data
    str1 db 80 dup (0)
    crlf db 0dh,0ah,"$"
.code
main proc
    mov ax,@data
    mov ds,ax 
    mov es,ax
    ; read string and store it into str
    lea di,str1
    call read_str
    ; go to a newline
    lea dx,crlf
    mov ah,9
    int 21h
; print string
display_str_:
        mov cx,bx
        lea si,str1
        mov ah,2
print_:
        lodsb
        mov dl,al
        int 21h
        loop print_
    mov ah,4ch
    int 21h
main endp

read_str proc near
; reads and stores a string
; input: DI offset of a string
; output: DI offset of string
; BX is the no. of chars to read
    push ax
    push di 
    cld
    xor bx,bx
    mov ah,1
    int 21h
while_:
    cmp al,0dh
    je end_while_
; if char is BACKSPACE 
    cmp al,8h
    jne else_    ; no, store in the string
; then
    dec di      ; yes, a backspace so mov str ptr back
    dec bx      ; decrement char counter
    jmp read_   ; go to read another char
else_:
    stosb       ; store char in string
    inc bx      ; increase char count

read_:
    int 21h
    jmp while_

end_while_:
    pop di 
    pop ax 
    ret
read_str endp
end main
