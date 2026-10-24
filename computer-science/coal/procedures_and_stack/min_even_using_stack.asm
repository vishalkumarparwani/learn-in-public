include Irvine32.inc
.data
minEven DWORD ?
foundEven BYTE 0
.code
main PROC
    mov ecx, 10
inputLoop:
    call ReadInt
    push eax
    loop inputLoop
    mov ecx, 10
findLoop:
    pop eax
    mov esi, eax
    mov ebx, 2
    xor edx, edx
    div ebx
    cmp edx, 0
    jne skip
    cmp foundEven, 0
    jne checkMin
    mov minEven, esi
    mov foundEven, 1
    jmp skip
checkMin:
    cmp esi, minEven
    jge skip
    mov minEven, esi
skip:
    loop findLoop
    cmp foundEven, 0
    je done
    mov eax, minEven
    call WriteInt
done:
    exit
main ENDP
END main
