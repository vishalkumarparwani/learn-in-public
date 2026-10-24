include irvine32.inc
.data
msg  byte "Enter the decimal: ",0
msg1 byte "Hight Blood Sugar",0
msg2 byte "High Systolic Blood pressure",0
msg3 byte "Diastolic blood pressure",0
msg4 byte "High Pulse",0
msg5 byte "High Hemoglobin",0
msg6 byte "High Body Temperature",0
msg7 byte "High Respiration Rate",0
msg8 byte "High Pain Level",0
msg9 byte "Urgent",0
msg10 byte "Intermediate",0
msg11 byte "Trivial",0
messageTable dword offset msg1, offset msg2, offset msg3, offset msg4, offset msg5, offset msg6, offset msg7, offset msg8

.code
main Proc
mov edx, 0
mov edx, offset msg
call writeString
call readInt
mov ecx, 8
mov ebx, 0
mov edi, 0
lea esi, messageTable
L1:
bt eax, ebx
jnc nextBit
mov edx, 0
mov edx, [esi + ebx*4]
call writeString
call crlf
inc edi
nextBit:
	inc ebx
LOOP L1

cmp edi, 5
ja URGENT
jbe three
three:
cmp edi, 3
jae INTERMEDIATE
jb TRIVIAL

URGENT:
mov edx, 0
mov edx, offset msg9
call writeString
call crlf
jmp FINAL
INTERMEDIATE:
mov edx, 0
mov edx, offset msg10
call writeString
call crlf
jmp FINAL
TRIVIAL:
mov edx, 0
mov edx, offset msg11
call writeString
call crlf
jmp FINAL
FINAL:
call dumpregs
exit
main endP
end main
