.model small
.stack 100h   
.data
    CR equ 0DH
    LF equ 0AH 
.code
main proc    
    mov ax,@data
    mov ds,ax   
    
    ; Multiplicand x Multiplier = Product -> AX for 16 bit & DX:AX for 32 bit
    ; Multiplicand must be stored in AL / AX . AL for 8 bit & AX for 16 bit
    ; Multiplier can be stored in any Byte or Word Register accordingly.
    
    ; 5 x 3 = 15
    ; AL = 5, BL = 3, then the product AX = 15  
    
    ; aaa
    ; aam
    ; aad
    
    mov al,3
    mov bl,3
    mul bl      ; ax = al x bl 
    
    mov dl,al
    add dl,'0'
    mov ah,2
    int 21h
    
EXIT:   
    mov ah,4ch
    int 21h
main endp
end main
    
