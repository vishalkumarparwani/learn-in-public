include irvine32.inc
.data
string byte "FastUniX",0
array byte '0','1','2','3','4','5','6','7','8','9'
msg1 byte "Password is Strong.",0
msg2 byte "Password must include at least 1 digit.",0
.code
main proc
mov ebx, 0
mov esi, offset array
Label1:
cmp ebx, 10
ja not_found
inc ebx
mov al, [esi]
inc esi
mov ecx, sizeof string
mov edi, offset string
cld
repne scasb
jne label1
found:
mov edx, offset msg1
jmp Quit
not_found:
mov edx, offset msg2
Quit:
call crlf
call writeString
exit
main endp
end main
