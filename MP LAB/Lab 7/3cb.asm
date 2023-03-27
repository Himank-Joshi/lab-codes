; Assuming data segment with array of signed bytes 'arr' and its length 'len'
; Code segment to perform bubble sort

section .data
    arr db -5, 10, -3, 0, 8, -1, 6   ; sample array of signed bytes
    len equ $-arr                  ; length of the array

section .text
    global _start

_start:
    mov ecx, len        ; move length of the array to ecx register
    dec ecx             ; decrement ecx since we need to compare the last two elements in the array only once

outer_loop:
    mov ebx, 0          ; set ebx to 0 to indicate that no swaps have been made in this iteration
    mov esi, arr        ; move the starting address of the array to esi register

inner_loop:
    mov al, [esi]       ; move the first byte to al register
    cmp al, [esi+1]     ; compare with the next byte in the array
    jle not_swap        ; jump if al is less than or equal to [esi+1]

    ; swap the bytes
    xchg al, [esi+1]    ; exchange al with [esi+1]
    mov [esi], al       ; move the new byte value to the first byte
    mov ebx, 1          ; set ebx to 1 to indicate a swap has been made

not_swap:
    inc esi             ; increment esi to move to the next byte in the array
    loop inner_loop     ; loop until ecx becomes zero

    cmp ebx, 1          ; check if a swap has been made in this iteration
    jne done_sorting    ; if no swap has been made, array is already sorted

    dec ecx             ; decrement ecx since the last element is already sorted
    jmp outer_loop      ; repeat outer loop until the array is completely sorted

done_sorting:
    ; code to print the sorted array
    mov eax, 4          ; system call to print to console
    mov ebx, 1          ; file descriptor for console (stdout)
    mov ecx, arr        ; move the starting address of the sorted array to ecx register
    mov edx, len        ; length of the array
    mov eax, 4          ; system call to print to console
    int 0x80            ; execute the system call

    ; exit program
    mov eax, 1          ; system call for exit
    xor ebx, ebx        ; exit code 0
    int 0x80            ; execute the system call
