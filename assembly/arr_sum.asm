.model small
.stack 100h
.data 
    twoD1 db 9 dup(?)  ; Flat representation of 3x3 array
    twoD2 db 9 dup(?)  ; Flat representation of 3x3 array
    sum   db 9 dup(?)  ; Flat representation of result array
    result db 0
    newline db 0Dh, 0Ah, '$'   ; Newline characters for printing

.code 
main proc
    mov ax, @data
    mov ds, ax

    ; Input first array
    mov si, 0  ; Index for flat array
    mov cx, 9  ; Total number of elements to input
input_first_array:
    mov result, 0  ; Reset result for each input
    
input_first_digit:
    mov ah, 1
    int 21h
    cmp al, 13  ; Check for Enter key
    je store_first_value
    
    ; Convert ASCII to numeric value
    sub al, '0'
    mov dl, al
    
    ; Multiply current result by 10 and add new digit
    mov al, result
    mov ah, 10
    mul ah
    add al, dl
    mov result, al
    
    jmp input_first_digit

store_first_value:
    mov al, result
    mov twoD1[si], al
    
    inc si
    loop input_first_array

    ; Input second array
    mov si, 0  ; Reset index
    mov cx, 9  ; Total number of elements to input
input_second_array:
    mov result, 0  ; Reset result for each input
    
input_second_digit:
    mov ah, 1
    int 21h
    cmp al, 13  ; Check for Enter key
    je store_second_value
    
    ; Convert ASCII to numeric value
    sub al, '0'
    mov dl, al
    
    ; Multiply current result by 10 and add new digit
    mov al, result
    mov ah, 10
    mul ah
    add al, dl
    mov result, al
    
    jmp input_second_digit

store_second_value:
    mov al, result
    mov twoD2[si], al
    
    inc si
    loop input_second_array

    ; Add two arrays
    mov si, 0  ; Index
    mov cx, 9  ; Total number of elements
add_arrays:
    mov al, twoD1[si]
    add al, twoD2[si]
    mov sum[si], al
    
    inc si
    loop add_arrays

    ; Print result array
    mov si, 0  ; Index
    mov cx, 9  ; Total number of elements
print_array:
    ; Convert to ASCII
    mov al, sum[si]
    add al, '0'
    
    ; Print digit
    mov dl, al
    mov ah, 2
    int 21h
    
    ; Print space
    mov dl, ' '
    mov ah, 2
    int 21h
    
    inc si
    
    ; Print newline every 3 elements
    push cx
    mov ax, si
    mov bl, 3
    div bl
    cmp ah, 0
    jne continue_print
    
    ; Print newline
    lea dx, newline
    mov ah, 9
    int 21h

continue_print:
    pop cx
    loop print_array

exit:
    mov ah, 4Ch
    int 21h
main endp
end main
