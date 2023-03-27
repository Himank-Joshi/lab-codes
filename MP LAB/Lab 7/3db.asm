;Program to perform Sorting of Signed Words using Bubble sort

data segment
    arr dw -3, 5, 1, -8, 0, 12, -2, 9 ;array to be sorted
    n dw 8 ;size of the array
data ends

code segment
start:
    mov ax, data
    mov ds, ax ;initialize data segment
    
    mov cx, [n] ;number of elements in array
    dec cx ;cx = n-1
    
    outer_loop:
        mov bx, 0 ;initialize bx to 0
        inner_loop:
            mov si, bx ;si = bx
            add si, bx ;si = 2*bx
            
            mov ax, [arr+si] ;ax = arr[bx]
            cmp ax, [arr+si+2] ;compare with arr[bx+1]
            jle skip_swap ;if ax <= arr[bx+1] skip the swap
            
            ;swap arr[bx] and arr[bx+1]
            xchg ax, [arr+si+2]
            mov [arr+si], ax
            
            skip_swap:
                inc bx ;increment bx
                cmp bx, cx ;check if bx < cx
                jl inner_loop ;repeat inner loop if bx < cx
        
        dec cx ;decrement cx
        jnz outer_loop ;repeat outer loop if cx != 0
    
    mov ax, 4c00h ;exit to operating system
    int 21h
code ends
