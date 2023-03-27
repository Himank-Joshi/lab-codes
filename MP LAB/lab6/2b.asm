; Assuming the four unsigned words are stored in variables named 'word1', 'word2', 'word3', and 'word4'
; Assuming the final GCD will be stored in a variable named 'final_gcd'
; Assuming DS and CS are defined

DATA SEGMENT
  word1 DW ?
  word2 DW ?
  word3 DW ?
  word4 DW ?
  final_gcd DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

; define function to find GCD of two unsigned words
; Input: AX = word1, BX = word2
; Output: AX = GCD value
GCD_FUNC PROC
  GCD_LOOP:
    CMP AX, BX ; compare AX and BX
    JA WORD1_GREATER ; if AX > BX, jump to WORD1_GREATER
    XCHG AX, BX ; exchange AX and BX
    JMP GCD_LOOP ; jump to GCD_LOOP

  WORD1_GREATER:
    SUB AX, BX ; subtract BX from AX
    CMP BX, 0 ; compare BX to zero
    JNE GCD_LOOP ; if BX is not zero, jump to GCD_LOOP

  RET ; return from function
GCD_FUNC ENDP

START:
  ; find the GCD of word1 and word2 using function
  MOV AX, word1
  MOV BX, word2
  CALL GCD_FUNC
  MOV final_gcd, AX ; store the GCD value in final_gcd

  ; find the GCD of final_gcd and word3 using function
  MOV AX, final_gcd
  MOV BX, word3
  CALL GCD_FUNC
  MOV final_gcd, AX ; store the GCD value in final_gcd

  ; find the GCD of final_gcd and word4 using function
  MOV AX, final_gcd
  MOV BX, word4
  CALL GCD_FUNC
  MOV final_gcd, AX ; store the GCD value in final_gcd

  ; exit program
  MOV AH, 4CH
  INT 21H

CODE ENDS
END START
