.MODEL SMALL
.STACK 100H
.DATA
RESULT DB 0
MLT DB 1
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
   
    LP:
        MOV AH,1
        INT 21H
        CMP AL,13
        JE EXIT
        SUB AL,48
        MOV CL,AL

        MOV AL,RESULT
        MOV BL,10
        MUL BL
        ADD AL,CL
        MOV RESULT,AL
        JMP LP
    EXIT:
   
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    MOV DL,RESULT
    INT 21H    
   
   
    MAIN ENDP
END MAIN
