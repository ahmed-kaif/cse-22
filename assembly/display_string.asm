.MODEL SMALL
.STACK 100H
.DATA
    MSG  DB  "HELLO!$"
.CODE
MAIN PROC
    ;initialize Data Segment
    MOV AX,@DATA
    MOV DS,AX
;display msg
    LEA DX,MSG
    MOV AH,9 ; call string function
    INT 21H
; Return to DOS
    MOV AH, 4CH
    INT 21H
MAIN ENDP
    END MAIN
