INCLUDE Irvine32.inc

.data

dividend dword 0D4A4h
divisor dword 0Ah

.code
main proc

mov eax, dividend
mov ebx, divisor

call recursiveProcedure

exit
main endP

recursiveProcedure Proc

cmp eax, 05h
jbe done

xor edx, edx
div ebx
call recursiveProcedure

done:
	ret

recursiveProcedure endP
end main
