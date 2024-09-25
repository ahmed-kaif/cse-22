.MODEL SMALL
.STACK 100H
.DATA
    CR EQU 0DH
    LF EQU 0AH
    MSG1  DB  "ENTER THREE LOWERCASE LETTER: $"
    MSG2  DB  CR,LF,"IN LOWERCASE IT IS: ",CR,LF 
    CHAR1 DB  ?,CR,LF
    CHAR2 DB  ?,CR,LF
    CHAR3 DB  ?,CR,LF,"$"
.CODE
MAIN PROC
;initialize Data Segment
    MOV AX,@DATA
    MOV DS,AX
;display msg
    LEA DX,MSG1
    MOV AH,9 ; call string function
    INT 21H
; take input
    MOV AH,1
    INT 21H
; Convert lower to upper
    SUB AL,20H
    MOV CHAR1,AL
; take input
    MOV AH,1
    INT 21H
; Convert lower to upper
    SUB AL,20H
    MOV CHAR2,AL
; take input
    MOV AH,1
    INT 21H
; Convert lower to upper
    SUB AL,20H
    MOV CHAR3,AL
; Print char
    LEA DX,MSG2
    MOV AH,9
    INT 21H
; Return to DOS
    MOV AH, 4CH
    INT 21H
MAIN ENDP
    END MAIN
