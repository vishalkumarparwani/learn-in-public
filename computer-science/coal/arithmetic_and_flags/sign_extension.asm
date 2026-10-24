include irvine32.inc
.data
msg1 byte "Enter negative num1: ",0
msg2 byte "Enter negative num2: ",0
num1 byte ?
newnum1 word ?
temp word ?
num2 word ?
newnum2 dword ?
msg3 byte "Num1 in word size : ",0
msg4 byte "Num2 in dword size : ",0
.code
main proc
mov edx,offset msg1
call writestring
call readint
mov num1,al
mov edx,offset msg2
call writestring
call readint
mov num2,ax
mov al,num1
cbw
mov newnum1,ax
mov edx,offset msg3
call writestring
call writeint
call crlf
mov ax, num2
cwd
mov eax,eax
shl edx,16
or eax,edx
mov newnum2, eax
mov edx,offset msg4
call writestring
call writeint
exit
main ENDP
end main
