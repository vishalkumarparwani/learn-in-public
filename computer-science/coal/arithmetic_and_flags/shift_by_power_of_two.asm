include irvine32.inc
.data
msg1 byte "Enter number: ",0
msg2 byte "Enter n: ",0
num dword ?
n byte ?
msg3 byte "Num x 2^n : ",0
msg4 byte "Num / 2^n : ",0
.code
main proc
mov edx,offset msg1
call writestring
call readdec
mov num,eax
mov edx,offset msg2
call writestring
call readdec
mov n,al
mov cl,n
mov eax,num
sal eax,cl
mov edx,offset msg3
call writestring
call writeint
call crlf
mov eax,num
sar eax,cl
mov edx,offset msg4
call writestring
call writeint
exit
main ENDP
end main
