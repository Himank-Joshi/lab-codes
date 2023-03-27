; Assuming the input HEX number is stored in a 2-byte variable named 'input_hex'
; Assuming the output BCD number will be stored in a 4-byte variable named 'output_bcd'
; Assuming DS and CS are defined

DATA SEGMENT
input_hex DW ? ; 2-byte input HEX number
output_bcd DB 4 DUP (?) ; 4-byte output BCD number
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
MOV AX, DATA ; initialize data segment
MOV DS, AX

MOV BX, input_hex ; load the input HEX number into BX

; convert thousands digit
MOV AL, BH ; load the high byte of BX into AL
AAM ; ASCII adjust for multiplication
MOV output_bcd, AH ; save the thousands digit in the output BCD number

; convert hundreds digit
MOV AL, BL ; load the low byte of BX into AL
AAM ; ASCII adjust for multiplication
MOV output_bcd + 1, AH ; save the hundreds digit in the output BCD number

; convert tens digit
MOV AL, BH ; load the high byte of BX into AL
AND AL, 0FH ; mask out the high nibble
AAM ; ASCII adjust for multiplication
MOV output_bcd + 2, AH ; save the tens digit in the output BCD number

; convert ones digit
MOV AL, BL ; load the low byte of BX into AL
AND AL, 0FH ; mask out the high nibble
AAM ; ASCII adjust for multiplication
MOV output_bcd + 3, AH ; save the ones digit in the output BCD number

; exit program
MOV AX, 4C00H
INT 21H
CODE ENDS
END START
//
Note: The above programs assume that the input and output variables are properly defined in the data segment and that the DS register is correctly set to point to the data segment. The programs also assume that the code segment is properly defined and that the instructions are executed in the correct order.
