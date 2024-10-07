.model small
.stack 100h   
.data
    CR equ 0DH
    LF equ 0AH 
    MSG1 DB "Enter 1st number: $"
    MSG2 DB "Enter 2nd Number: $"
    MSG3 DB "Sum = "
    sum  DB ?,CR,LF,"$"
    MSG4 DB "Difference = "
    diff DB ?,CR,LF,"$"
.code
main proc    
    mov ax,@data
    mov ds,ax
    
    lea dx,MSG1
    mov ah,9
    int 21h
    
    ; 1st number input
    mov ah,1
    int 21h
    sub al,'0'
    mov bl,al
    
    add sum,bl
    add sum,'0' 
    
    mov ah,2
    mov dl,CR
    int 21h
    mov dl,LF
    int 21h
           
    ; 2nd number input   
    lea dx,MSG2
    mov ah,9
    int 21h 
    
    mov ah,1
    int 21h
    sub al,'0'
    add sum,al
    
    cmp bl,al
    js level1

    sub bl,al
    mov diff,bl  
    add diff,'0' 
    jmp PRINT
    
level1:
    sub al,bl
    mov diff,al
    add diff,'0'
    jmp PRINT
PRINT:    
    mov ah,2
    mov dl,CR
    int 21h
    mov dl,LF
    int 21h
    
    lea dx,MSG3
    mov ah,9
    int 21h
    
    lea dx,MSG4
    mov ah,9
    int 21h
   
    mov ah,4ch
    int 21h
main endp
end main
    
