include irvine32.inc
.data
testSubject1 dword 1, 2, 5, 5, 5, 5, 5, 6
size1 dword lengthof testSubject1
testSubject2 dword 5, 5, 5, 5, 1, 5
size2 dword lengthof testSubject2
testSubject3 dword 5, 5, 5, 5, 5
size3 dword lengthof testSubject3

trueMsg byte "Found five consecutive 5s",0
falseMsg byte "Did not found five consecutive 5s",0

.code

FindFive Proto,
	arrPtr : PTR Dword,
	arrSize : Dword

main proc

Invoke FindFive, addr testSubject1, size1
call printResult
call crlf

Invoke FindFive, addr testSubject2, size2
call printResult
call crlf

Invoke FindFive, addr testSubject3, size3
call printResult
call crlf

exit
main endp

FindFive Proc USES esi ecx edx,
	arrPtr : PTR Dword,
	arrSize : dword

	mov ecx, arrSize
	mov esi, arrPtr

	mov edx, 0
	cmp ecx, 0
	je not_found

	L1:
		cmp dword ptr [esi], 5
		jne reset
		inc edx
		cmp edx, 5
		je found
		jmp next

		reset:
		mov edx, 0
		
		next:
		add esi, 4
		LOOP L1

		not_found:
		mov eax, 0
		ret

		found:
		mov eax, 1
		ret
FindFive endP

printResult Proc

cmp eax, 1
jne notFound
mov edx, offset trueMsg
call writeString
jmp ending

notFound:
mov edx, offset falseMsg
call writeString

ending:
call crlf
ret

printResult endP
end main
