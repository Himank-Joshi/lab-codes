; Assuming the input HEX number is stored in a 1-byte variable named 'input_hex'
; Assuming the output BCD number will be stored in a 1-byte variable named 'output_bcd'
; Assuming DS and CS are defined

DATA SEGMENT
  input_hex DB ? ; 1-byte input HEX number
  output_bcd DB ? ; 1-byte output BCD number
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
MOV AX, DATA ; initialize data segment
MOV DS, AX

MOV AL, input_hex ; load the input HEX number into AL
AAM ; ASCII adjust for multiplication
MOV output_bcd, AH ; save the tens digit in the output BCD number
MOV output_bcd + 1, AL ; save the ones digit in the output BCD number

; exit program
MOV AX, 4C00H
INT 21H
CODE ENDS
END START