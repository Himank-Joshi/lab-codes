; Assuming the two unsigned bytes are stored in variables named 'byte1' and 'byte2'
; Assuming the final LCM will be stored in a variable named 'final_lcm'
; Assuming DS and CS are defined

DATA SEGMENT
  byte1 DB ?
  byte2 DB ?
  final_lcm DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
  MOV AX, @DATA ; initialize data segment
  MOV DS, AX

  ; find the GCD of byte1 and byte2 using Euclidean algorithm
  MOV AL, byte1 ; move byte1 to AL
  MOV BL, byte2 ; move byte2 to BL
  GCD_LOOP:
    CMP AL, BL ; compare AL and BL
    JA WORD1_GREATER ; if AL > BL, jump to WORD1_GREATER
    XCHG AL, BL ; exchange AL and BL
  WORD1_GREATER:
    SUB AL, BL ; subtract BL from AL
    CMP BL, 0 ; compare BL to zero
    JNE GCD_LOOP ; if BL is not zero, jump to GCD_LOOP
  MOV final_lcm, AX ; store the GCD value in final_lcm

  ; find the LCM of byte1 and byte2 using GCD value
  MOV AL, byte1 ; move byte1 to AL
  MUL byte2 ; multiply byte1 by byte2
  DIV final_lcm ; divide the result by the GCD value
  MOV final_lcm, AX ; store the LCM value in final_lcm

  ; exit program
  MOV AH, 4CH
  INT 21H

CODE ENDS
END START
