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

; define macro to find GCD of two unsigned words
GCD_MACRO MACRO WORD1, WORD2, GCD_VAR
  MOV AX, WORD1
  MOV BX, WORD2

  GCD_LOOP:
    CMP AX, BX ; compare AX and BX
    JA WORD1_GREATER ; if AX > BX, jump to WORD1_GREATER
    XCHG AX, BX ; exchange AX and BX
    JMP GCD_LOOP ; jump to GCD_LOOP

  WORD1_GREATER:
    SUB AX, BX ; subtract BX from AX
    CMP BX, 0 ; compare BX to zero
    JNE GCD_LOOP ; if BX is not zero, jump to GCD_LOOP

  MOV GCD_VAR, AX ; move the GCD value in AX to GCD_VAR
ENDM ; end of macro definition

START:
  ; find the GCD of word1 and word2 using macro
  GCD_MACRO word1, word2, final_gcd

  ; find the GCD of final_gcd and word3 using macro
  GCD_MACRO final_gcd, word3, final_gcd

  ; find the GCD of final_gcd and word4 using macro
  GCD_MACRO final_gcd, word4, final_gcd

  ; exit program
  MOV AH, 4CH
  INT 21H

CODE ENDS
END START
