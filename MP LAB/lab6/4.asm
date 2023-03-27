; Assuming the four unsigned bytes are stored in variables named 'byte1', 'byte2', 'byte3', and 'byte4'
; Assuming the final LCM will be stored in a variable named 'final_lcm'
; Assuming DS and CS are defined

DATA SEGMENT
  byte1 DB ?
  byte2 DB ?
  byte3 DB ?
  byte4 DB ?
  final_lcm DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

; function to find LCM of two unsigned bytes
find_lcm:
  ; input: AL = byte1, BL = byte2
  ; output: AX = LCM of byte1 and byte2

  PUSH AX ; save registers
  PUSH BX
  PUSH CX

  ; find GCD of byte1 and byte2 using Euclidean algorithm
  GCD_LOOP:
    CMP AL, BL ; compare AL and BL
    JA WORD1_GREATER ; if AL > BL, jump to WORD1_GREATER
    XCHG AL, BL ; exchange AL and BL
  WORD1_GREATER:
    SUB AL, BL ; subtract BL from AL
    CMP BL, 0 ; compare BL to zero
    JNE GCD_LOOP ; if BL is not zero, jump to GCD_LOOP

  ; calculate LCM of byte1 and byte2 using GCD value
  MOV BL, byte1 ; move byte1 to BL
  MUL byte2 ; multiply byte1 by byte2
  DIV AL ; divide the result by the GCD value
  MOV AX, DX ; move the result to AX

  POP CX ; restore registers
  POP BX
  POP AX
  RET ; return from function

START:
  MOV AX, @DATA ; initialize data segment
  MOV DS, AX

  ; find LCM of byte1, byte2, byte3, and byte4
  MOV AL, byte1 ; move byte1 to AL
  MOV BL, byte2 ; move byte2 to BL
  CALL find_lcm ; find LCM of byte1 and byte2
  MOV CX, AX ; move the result to CX

  MOV AL, byte3 ; move byte3 to AL
  MOV BL, byte4 ; move byte4 to BL
  CALL find_lcm ; find LCM of byte3 and byte4
  MUL CX ; multiply the result by CX
  MOV final_lcm, AX ; store the final LCM value in final_lcm

  ; exit program
  MOV AH, 4CH
  INT 21H

CODE ENDS
END START
