; Assuming the unsigned byte is stored in a variable named 'num'
; Assuming the final factorial value will be stored in a variable named 'factorial'
; Assuming DS and CS are defined

DATA SEGMENT
  num DB ?
  factorial DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

; function to find factorial of unsigned byte using recursion
find_factorial:
  ; input: AL = num
  ; output: AX = factorial of num

  PUSH AX ; save registers
  PUSH BX
  PUSH CX

  CMP AL, 1 ; compare AL to 1
  JBE FACTORIAL_IS_1 ; if AL is less than or equal to 1, jump to FACTORIAL_IS_1

  DEC AL ; decrement AL
  CALL find_factorial ; recursively call find_factorial with the decremented value of AL
  MUL AL ; multiply the result by the decremented value of AL

FACTORIAL_IS_1:
  MOV AX, DX ; move the result to AX

  POP CX ; restore registers
  POP BX
  POP AX
  RET ; return from function

START:
  MOV AX, @DATA ; initialize data segment
  MOV DS, AX

  ; find factorial of num using recursion
  MOV AL, num ; move num to AL
  CALL find_factorial ; find factorial of num
  MOV factorial, AX ; store the final factorial value in factorial

  ; exit program
  MOV AH, 4CH
  INT 21H

CODE ENDS
END START
