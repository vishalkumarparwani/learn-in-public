include irvine32.inc
.data
eValue dword ?
dValue dword ?
value dword ?
key	dword ?
msg1 byte "Enter the value: ",0
msg2 byte "Enter the key: ",0
msg3 byte "Encrypted value: ",0
msg4 byte "Decrypted value: ",0
.code
main Proc
mov edx, offset msg1
call writeString
call readInt
mov value, eax
call crlf
mov edx, offset msg2
call writeString
call readInt
mov key, eax
call crlf
mov eax, value
mov ecx, key
ROL eax, cl
mov eValue, eax
mov edx, offset msg3
call writeString
call writeInt
call crlf
mov eax, eValue
mov ecx, key
ROR eax, cl
mov dValue, eax
mov edx, offset msg4
call writeString
call writeInt
call crlf
call dumpregs
exit
main endP
end main
