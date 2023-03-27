; Assuming the array of words is stored in a variable named 'arr'
; Assuming the length of the array is stored in a variable named 'len'
; Assuming DS and CS are defined

DATA SEGMENT
  arr DW 1, 4, 2, 5, 3 ; example array of unsigned words
  len DW 5 ; length of the array
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

; function to perform selection sort on an array of unsigned words
sort_unsigned_words:
  ; input: arr = address of the array, len = length of the array
  ; output: sorted array

  MOV BX, 0 ; initialize index to 0

outer_loop:
  CMP BX, len ; compare index to length
  JAE DONE ; if index is greater than or equal to length, we're done sorting

  MOV CX, BX ; initialize smallest index to current index
  MOV AX, [arr+BX] ; initialize smallest value to current value

  inner_loop:
    INC CX ; increment smallest index
    CMP CX, len ; compare smallest index to length
    JAE swap ; if smallest index is greater than or equal to length, swap values

    MOV DX, [arr+CX] ; load value of next element
    CMP DX, AX ; compare value of next element to current smallest value
    JB update ; if next element is less than current smallest value, update smallest value

    JMP inner_loop ; continue inner loop

  update:
    MOV AX, DX ; update smallest value
    JMP inner_loop ; continue inner loop

  swap:
    MOV DX, [arr+BX] ; move current value to temporary location
    MOV [arr+BX], AX ; move smallest value to current location
    MOV [arr+CX], DX ; move current value to smallest location

    INC BX ; increment index
    JMP outer_loop ; continue outer loop

DONE:
  RET ; return from function

CODE ENDS
END
