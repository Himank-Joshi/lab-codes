; Assuming the first unsigned word is stored in a variable named 'word1'
; Assuming the second unsigned word is stored in a variable named 'word2'
; Assuming the GCD will be stored in a variable named 'gcd'
; Assuming DS and CS are defined

DATA SEGMENT
  word1 DW ?
  word2 DW ?
  gcd DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

PROC GCD_PROC ; define procedure to find GCD of two unsigned words
  MOV AX, word1
  MOV BX, word2

  GCD_LOOP:
    CMP AX, BX ; compare AX and BX
    JA WORD1_GREATER ; if AX > BX, jump to WORD1_GREATER
    XCHG AX, BX ; exchange AX and BX
    JMP GCD_LOOP ; jump to GCD_LOOP

  WORD1_GREATER:
    SUB AX, BX ; subtract BX from AX
    CMP BX, 0 ; compare BX to zero
    JNE GCD_LOOP ; if BX is not zero, jump to GCD_LOOP

  MOV gcd, AX ; move the GCD into gcd variable

  RET
ENDP

START:
  MOV AX, DATA ; initialize data segment
  MOV DS, AX

  CALL GCD_PROC ; call the GCD procedure to find the GCD

  ; exit program
  MOV AX, 4C00H
  INT 21H
CODE ENDS
END START
