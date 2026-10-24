INCLUDE Irvine32.inc

.data

prompt byte "Enter a string: ",0
buffer byte 100 DUP(0)
byteCount dword ?


.code
main proc

mov edx, offset prompt
call writeString

mov edx, offset buffer
mov ecx, sizeof buffer
call readString
mov byteCount, eax

mov esi, offset buffer
mov edi, offset buffer
mov ecx, byteCount

cmp ecx, 0
je Result

scanLoop:
mov al, [esi]
cmp al, 0
je Result
cmp al, '#'
je next_Char

mov [edi], al
inc edi
next_Char:
inc esi
jmp scanLoop

Result:
mov byte ptr [edi], 0
mov edx, offset buffer
call writeString

exit
main endP
end main
