.model small
.stack 100h
.data
    A dw 3
    B dw 2
.code
main proc
    MOV AX,@data
    MOV DS,AX

    MOV AH,1
    INT 21h

    SUB AL,30h ; 48 / '0'
    MOV BL,AL

    MOV AH,1
    INT 21h

    SUB AL,30h
    ADD AL,BL
    
    MOV DL,AL
    ADD DL,30h
    MOV AH,2
    INT 21h

    MOV AH,4Ch
    INT 21H

main endp
end main
