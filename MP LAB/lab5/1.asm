; Assuming the input BCD number is stored in a 4-byte variable named 'input_bcd'
; Assuming the output HEX number will be stored in a 4-byte variable named 'output_hex'
; Assuming DS and CS are defined

DATA SEGMENT
  input_bcd DB 4 DUP (?) ; 4-byte input BCD number
  output_hex DB 4 DUP (?) ; 4-byte output HEX number
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
  MOV AX, DATA ; initialize data segment
  MOV DS, AX

  MOV CX, 4 ; loop 4 times for each BCD digit

  MOV AL, input_bcd + 3 ; load the most significant BCD digit into AL
  DAA ; convert BCD to binary-coded decimal
  MOV BL, 10 ; load the divisor for division
  DIV BL ; divide AL by BL, quotient in AH, remainder in AL
  MOV AH, AL ; save the remainder in AH
  MOV AL, input_bcd + 2 ; load the second most significant BCD digit into AL
  DAA ; convert BCD to binary-coded decimal
  ADD AL, AH ; add the remainder from the previous division to AL
  MOV AH, 0 ; clear AH
  MOV BL, 10 ; load the divisor for division
  DIV BL ; divide AL by BL, quotient in AH, remainder in AL
  MOV output_hex + 3, AH ; save the quotient in the output HEX number

  MOV AL, input_bcd + 1 ; load the second least significant BCD digit into AL
  DAA ; convert BCD to binary-coded decimal
  MOV BL, 10 ; load the divisor for division
  DIV BL ; divide AL by BL, quotient in AH, remainder in AL
  MOV AH, AL ; save the remainder in AH
  MOV AL, input_bcd ; load the least significant BCD digit into AL
  DAA ; convert BCD to binary-coded decimal
  ADD AL, AH ; add the remainder from the previous division to AL
  MOV AH, 0 ; clear AH
  MOV BL, 10 ; load the divisor for division
  DIV BL ; divide AL by BL, quotient in AH, remainder in AL
  MOV output_hex + 2, AH ; save the quotient in the output HEX number

  MOV AH, 0 ; clear AH
  MOV AL, input_bcd ; load the least significant BCD digit into AL
  DAA ; convert BCD to binary-coded decimal
  MOV BL, 10 ; load the divisor for division
  DIV BL ; divide AL by BL, quotient in AH, remainder in AL
  MOV output_hex + 1, AH ; save the quotient in the output HEX number

  MOV output_hex, AL ; save the remainder in the output HEX number

  ; exit program
  MOV AX, 4C00H
  INT 21H
CODE ENDS
END START
