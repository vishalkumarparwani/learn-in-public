include irvine32.inc
.data
string1 byte "ABCDEFGHIJ",0
string2 byte "Spaces Found!",0
string3 byte "Spaces not found",0
.code
main proc
mov edi, offset string1
mov al, ' '
mov ecx, sizeof string1
cld
repne scasb
jnz notFound
dec edi
mov edx, offset string2
call writeString
jmp quit
notFound:
mov edx, offset string3
call writeString
jmp quit
quit:
exit
main endp
end main
