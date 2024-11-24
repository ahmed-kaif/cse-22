.model small
.stack 100h
.data 
    CR equ 0dh
    LF equ 0ah
    A db 1,8,2,3,7,4
    max_msg db "Max: "
    max db -128,CR,LF,"$"
    min_msg db "Min: "
    min db 127,CR,LF,"$"
.code
main proc
    mov ax,@data
    mov ds,ax
    mov cx,6
    xor bx,bx  ; set bx = 0
max_loop_:
    mov al,max
    cmp A[bx],al
    jg change_max
    inc bx
    loop max_loop_
    jmp min_start_
change_max:
    mov al,A[bx]
    mov max,al
    jmp max_loop_
min_start_:
    mov cx,6    ; set loop counter to 6
    xor ax,ax   ; set ax = 0
    xor bx,bx   ; set bx = 0
min_loop_:
    mov al,min
    cmp A[bx],al
    jl change_min
    inc bx
    loop min_loop_
    jmp print_
change_min:
    mov al,A[bx]
    mov min,al
    jmp min_loop_
print_:      
    add max,'0'
    lea dx,max_msg
    mov ah,9
    int 21h  
    add min,'0'
    lea dx,min_msg
    mov ah,9
    int 21h
exit_:
    mov ah,4ch 
    int 21h
main endp
    end main
    
