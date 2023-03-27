; Assuming the array of bytes is stored in a variable named 'arr'
; Assuming the length of the array is stored in a variable named 'len'
; Assuming DS and CS are defined

DATA SEGMENT
  arr DB 3, 7, 1, 5, 2 ; example array of unsigned bytes
  len DW 5 ; length of the array
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

; function to perform bubble sort on an array of unsigned bytes
sort_unsigned_bytes:
  ; input: arr = address of the array, len = length of the array
  ; output: sorted array

  MOV BX, len ; initialize index to length

outer_loop:
  DEC BX ; decrement index
  JZ DONE ; if index is 0, we're done sorting

  MOV CX, 0 ; initialize inner index to 0

inner_loop:
  CMP CX, BX ; compare inner index to outer index
  JAE outer_loop ; if inner index is greater than or equal to outer index, continue outer loop

  MOV AL, [arr+CX] ; load value of current element
  MOV DL, [arr+CX+1] ; load value of next element
  CMP DL, AL ; compare current element to next element
  JAE skip_swap ; if current element is less than or equal to next element, skip swap

  MOV [arr+CX], DL ; move next element to current location
  MOV [arr+CX+1], AL ; move current element to next location

skip_swap:
  INC CX ; increment inner index
  JMP inner_loop ; continue inner loop

DONE:
  RET ; return from function

CODE ENDS
END
