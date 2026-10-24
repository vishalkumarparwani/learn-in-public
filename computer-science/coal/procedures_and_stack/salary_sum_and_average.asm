INCLUDE Irvine32.inc
.data
salaries DWORD 5 DUP(?)
sum DWORD ?
avg DWORD ?
msgSum BYTE "Sum of salaries: ",0
msgAvg BYTE "Average of salaries: ",0
.code
main PROC
    call InputSalaries
    call CalcSumAvg
    call DisplayAll
    exit
main ENDP
InputSalaries PROC
    mov ecx, LENGTHOF salaries
    mov esi, OFFSET salaries
L1:
    call ReadInt
    mov [esi], eax
    add esi, TYPE salaries
    loop L1
    ret
InputSalaries ENDP
CalcSumAvg PROC
    mov ecx, LENGTHOF salaries
    mov esi, OFFSET salaries
    xor eax, eax
    xor ebx, ebx
L2:
    add ebx, [esi]
    add esi, TYPE salaries
    loop L2
    mov sum, ebx
    mov eax, ebx
    mov ebx, LENGTHOF salaries
    xor edx, edx
    div ebx
    mov avg, eax
    ret
CalcSumAvg ENDP
DisplayAll PROC
    mov edx, OFFSET msgSum
    call WriteString
    mov eax, sum
    call WriteInt
    call Crlf
    mov edx, OFFSET msgAvg
    call WriteString
    mov eax, avg
    call WriteInt
    call Crlf
    ret
DisplayAll ENDP
END main
