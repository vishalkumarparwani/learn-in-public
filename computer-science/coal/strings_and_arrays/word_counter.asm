include irvine32.inc
.data
msg1 byte "Enter a string: ",0
msg2 byte "Number of words: ",0
input byte 50 dup(?)
count dword 0
.code
main PROC
mov edx, OFFSET msg1
call WriteString
mov edx, OFFSET input
mov ecx, SIZEOF input
call ReadString
lea esi, input
mov ecx,eax
mov count,0
mov bl,0
l1:
lodsb
cmp al,0
je finish
cmp al,' '
je space
cmp bl,1
je l1
mov bl,1
inc count
jmp l1
space:
mov bl,0
jmp l1
finish:
mov edx, OFFSET msg2
call WriteString
mov eax,count
call writedec
call crlf
exit
main ENDP
END main
