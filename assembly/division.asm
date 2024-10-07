.model small
.stack 100h   
.data
    CR equ 0DH
    LF equ 0AH          
    msg2 db CR,LF,"Remainder = "
    remainder db ?,CR,LF,"$"
    msg1 db "Quotient = "
    quotient db ?,CR,LF,"$"
.code
main proc    
    mov ax,@data
    mov ds,ax   
    
    ; (16 bit) Dividend / (8 bit) Divisor = (8 bit) Quotient & (8 bit) Remainder
    ; AX = Dividend
    ; Divisor = Byte Register / Byte Variable (for 8 bit)
    ; AL = Quotient & AH = Remainder
    
    mov ax,5
    mov bl,2
    div bl          
    mov quotient, al 
    add quotient,'0'
    mov remainder,ah
    add remainder,'0'
                            
    lea dx,msg1
    mov ah,9
    int 21h
           
    lea dx,msg2
    mov ah,9
    int 21h
    
EXIT:   
    mov ah,4ch
    int 21h
main endp
end main
    
