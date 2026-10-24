include irvine32.inc
.data
msg1 byte "Enter num1: ",0
msg2 byte "Enter num2: ",0
num1 dword ?
num2 dword ?
ans1 dword ?
ans2 dword ?
msg3 byte "Result of add : ",0
msg4 byte "Result of adc : ",0
msg5 byte "Result of sub : ",0
msg6 byte "Result of sbb : ",0
.code
main proc
mov edx,offset msg1
call writestring
call readdec
mov num1,eax
mov edx,offset msg2
call writestring
call readdec
mov num2,eax
mov eax,num1
add eax,num2
mov ans1,eax
mov edx,offset msg3
call writestring
call writedec
call crlf
stc
mov eax, num1
adc eax, num2
mov ans2, eax
mov edx,offset msg4
call writestring
call writedec
call crlf
mov eax,num1
sub eax,num2
mov edx,offset msg5
call writestring
call writedec
call crlf
stc
mov eax,num1
sbb eax,num2
mov edx,offset msg6
call writestring
call writedec
call crlf
exit
main ENDP
end main
