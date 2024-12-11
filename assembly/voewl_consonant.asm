title program to count vowel and consonant 
.model small
.stack 100h
.data
    str db 80 dup(0)
    crlf db 0dh,0ah,"$"
    vowels db "AEIOUaeiou"
    consonants db "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz"
    vowel_count db 0
    consonant_count db 0
.code
main proc
    mov ax,@data
    mov ds,ax 
    mov es,ax
    
; read string
    lea di,str 
    call read_str

; print newline
    lea dx,crlf
    mov ah,9
    int 21h

; count vowel and consonant
    mov si,di
    cld 
repeat_:
; load a string character into AL
    lodsb
    lea di,vowels
    mov cx,10
    repne scasb             ; is char a vowel?
    jne check_consonant_    ; not a vowel, so check if consonant
    inc vowel_count         ; yes, a vowel, so increase vowel count
    jmp until_              ; go to next char

check_consonant_:
    lea di,consonants
    mov cx,42
    repne scasb
    jne until_              ; no, not a consonant, go to next char
    inc consonant_count     ; yes, consonant
    
until_:
    dec bx                  ; BX has no. of chars
    jne repeat_             ; repeat until end of chars

print_vowel:
    mov ah,2
    mov dl,vowel_count
    add dl,'0'
    int 21h
; print newline
    lea dx,crlf
    mov ah,9
    int 21h
    
    mov ah,2
    mov dl,consonant_count
    add dl,'0'
    int 21h
; dos exit
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

