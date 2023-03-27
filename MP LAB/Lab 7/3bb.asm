; Initialize data segment
data segment
    array dw 10, 20, 5, 15, 30   ; array to be sorted
    n dw 5                       ; size of array
data ends

; Initialize code segment
code segment
start:
    mov ax, data                ; set up data segment
    mov ds, ax

    ; Outer loop for number of passes
    mov cx, [n]                 ; number of passes = size of array - 1
    dec cx                      ; decrement by 1 to exclude last element
    outerLoop:
        ; Inner loop for each pass
        mov bx, 0               ; initialize inner loop counter
        innerLoop:
            cmp bx, cx          ; compare inner loop counter with number of passes
            jge next            ; if greater or equal, jump to next outer loop
            mov si, bx           ; set SI to inner loop counter
            add si, si           ; multiply by 2 (size of word)
            mov ax, [array + si] ; get current element
            mov di, bx           ; set DI to inner loop counter
            inc di               ; increment DI
            add di, di           ; multiply by 2 (size of word)
            mov bx, [array + di] ; get next element
            cmp ax, bx           ; compare current and next elements
            jle skip             ; if current is less or equal, skip to next element
            ; swap current and next elements
            mov [array + si], bx
            mov [array + di], ax
        skip:
            inc bx              ; increment inner loop counter
            jmp innerLoop       ; repeat inner loop
    next:
        dec cx                  ; decrement number of passes
        cmp cx, 0               ; compare with 0
        jg outerLoop            ; if greater, repeat outer loop

    ; Display sorted array
    mov cx, [n]                 ; set up loop counter
    mov si, offset array        ; set up pointer to array
    displayLoop:
        mov ax, [si]            ; get current element
        call printUnsignedWord  ; print unsigned word
        add si, 2               ; increment pointer to next element
        loop displayLoop        ; repeat loop for each element

    ; Exit program
    mov ah, 4ch                 ; set up exit code
    mov al, 0                   ; return 0
    int 21h                     ; interrupt to exit program

; Subroutine to print unsigned word
printUnsignedWord proc
    push bx                     ; save registers
    push cx
    push dx
    mov bx, 10                  ; set up divisor
    xor cx, cx                  ; initialize counter
    div bx                      ; divide by 10
    push dx                     ; push remainder
    inc cx                      ; increment counter
    cmp ax, 0                   ; compare quotient with 0
    jnz printUnsignedWord       ; if not zero, repeat loop
    printLoop:
        pop dx                  ; pop remainder from stack
        add dl, '0'             ; convert to character
        mov ah, 2h              ; set up print function
        int 21h                 ; interrupt to print character
        loop printLoop          ; repeat loop for each remainder
    pop dx                      ; restore registers
    pop cx
    pop bx
    ret
printUnsignedWord endp

code ends
end start
