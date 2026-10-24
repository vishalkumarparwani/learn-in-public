INCLUDE Irvine32.inc

.data

prompt byte "Enter a string: ",0
buffer byte 100 DUP(0)
byteCount dword ?

vowelMsg byte "Vowel Count:",0
msg1 byte "a or A = ",0
msg2 byte "e or E = ",0
msg3 byte "i or I = ",0
msg4 byte "o or O = ",0
msg5 byte "u or U = ",0

countForA dword 0
countForE dword 0
countForI dword 0
countForO dword 0
countForU dword 0

.code
main proc

mov edx, offset prompt
call writeString

mov edx, offset buffer
mov ecx, sizeof buffer
call readString
mov byteCount, eax

mov ecx, byteCount
mov esi, offset buffer

cmp ecx, 0
je printResult

loop_label:
	mov al, [esi]
	cmp al, 'A'
	je inc_A
	cmp al, 'a'
	je inc_A

	cmp al, 'E'
	je inc_E
	cmp al, 'e'
	je inc_E

	cmp al, 'I'
	je inc_I
	cmp al, 'i'
	je inc_I

	cmp al, 'O'
	je inc_O
	cmp al, 'o'
	je inc_O

	cmp al, 'U'
	je inc_U
	cmp al, 'u'
	je inc_U
	jmp next_Char

	inc_A:
	inc countForA
	jmp next_Char

	inc_E:
	inc countForE
	jmp next_Char

	inc_I:
	inc countForI
	jmp next_Char

	inc_O:
	inc countForO
	jmp next_Char

	inc_U:
	inc countForU
	jmp next_Char

next_Char:
	inc esi

LOOP loop_label

printResult:

mov edx, offset vowelMsg
call writeString
call crlf
call crlf

mov edx, offset msg1
call writeString
mov eax, countForA
call writeInt
call crlf

mov edx, offset msg3
call writeString
mov eax, countForI
call writeInt
call crlf

mov edx, offset msg5
call writeString
mov eax, countForU
call writeInt


mov edx, offset msg2
call writeString
mov eax, countForE
call writeInt
call crlf

mov edx, offset msg4
call writeString
mov eax, countForO
call writeInt

exit
main endP
end main
