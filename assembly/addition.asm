.model small
.stack 100h
.data
    A dw 3
    B dw 2
.code
main proc
MOV AX,@data
MOV DS,AX

MOV AX,A
ADD AX,B

MOV DX,AX
ADD DX,30h
MOV AH,2
INT 21h

MOV AH,4CH
INT 21H

main endp
end main
