INCLUDE Irvine32.inc
.data
kelvin DWORD ?
celsius DWORD ?
fahrenheit DWORD ?
msgK BYTE "Kelvin: ",0
msgC BYTE "Celsius: ",0
msgF BYTE "Fahrenheit: ",0
msgFlag BYTE "Stored Flags: ",0
.code
main PROC
    call ReadInt
    mov kelvin, eax
    mov eax, kelvin
    sub eax, 273
    mov celsius, eax
    pushfd
    mov eax, celsius
    mov ebx, 9
    mul ebx
    mov ebx, 5
    div ebx
    add eax, 32
    mov fahrenheit, eax
    mov edx, OFFSET msgK
    call WriteString
    mov eax, kelvin
    call WriteInt
    call Crlf
    mov edx, OFFSET msgC
    call WriteString
    mov eax, celsius
    call WriteInt
    call Crlf
    mov edx, OFFSET msgF
    call WriteString
    mov eax, fahrenheit
    call WriteInt
    call Crlf
    mov edx, OFFSET msgFlag
    call WriteString
    pop eax
    push eax
    call WriteHex
    call Crlf
    mov edx, OFFSET msgFlag
    call WriteString
    pop eax
    call WriteHex
    call Crlf
    exit
main ENDP
END main
