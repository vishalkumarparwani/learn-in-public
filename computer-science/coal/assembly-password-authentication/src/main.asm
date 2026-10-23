; ============================================================
; Password Manager - COAL Project
; Saves a password to a file and checks it on login using a
; basic rotate cipher
; ============================================================

include irvine32.inc

.data

fileName        byte "userpass.txt",0
fileHandle      dword ?

asknewpassword  byte "Enter new Password: ",0
Askpassword     byte "Enter password: ",0
validPass       byte "Password accepted.",0
invalidPass     byte "Invalid password.",0
strongPassMsg   byte "Strong Password",0
weakPassMsg     byte "Password is weak. It must have at least 1 digit, 1 symbol, and 1 uppercase letter.",0
pauseMsg        byte "Press any key to continue...",0

banner1         byte "==================================",0
banner2         byte "         PASSWORD MANAGER          ",0
banner3         byte "==================================",0

password        byte 20 dup(?)
pass            byte 20 dup(0)
sizeString      dword 20
key             byte 5

.code
main PROC

    mov eax, 0Fh
    call SetTextColor
    call Clrscr
    call printBanner

    call ReadPassFromFile
    jnc startLogin

    call createNewFile

    mov edx, OFFSET pauseMsg
    call WriteString
    call ReadChar

startLogin:
    call Clrscr
    call printBanner
    call decryptAndCompare
    call crlf

    exit
main ENDP

;--------------------------------------------------------------
; prints the title box at the top, cyan looks decent on the
; default black console
;--------------------------------------------------------------
printBanner PROC
    mov eax, 0Bh
    call SetTextColor

    mov edx, OFFSET banner1
    call WriteString
    call crlf
    mov edx, OFFSET banner2
    call WriteString
    call crlf
    mov edx, OFFSET banner3
    call WriteString
    call crlf
    call crlf

    mov eax, 0Fh
    call SetTextColor
    ret
printBanner ENDP

;--------------------------------------------------------------
; runs when there is no password file yet, asks for a new
; password, checks it, encrypts it, saves it
;--------------------------------------------------------------
createNewFile PROC
    call askAndValidatePassword
    call Encrypt
    call savePassToFile
    ret
createNewFile ENDP

;--------------------------------------------------------------
; loads the saved password from the file, sets carry flag if
; the file is not found yet (first run)
;--------------------------------------------------------------
ReadPassFromFile PROC
    mov edx, OFFSET fileName
    call OpenInputFile
    cmp eax, INVALID_HANDLE_VALUE
    je FileMissing

    mov fileHandle, eax
    mov edx, OFFSET password
    mov ecx, 19                    ; leaving 1 byte for the null
    call ReadFromFile
    mov sizeString, eax

    ; file doesn't have a null at the end so add it manually
    ; or comparing later breaks
    mov edi, eax
    mov password[edi], 0

    mov eax, fileHandle
    call CloseFile

    clc
    ret

FileMissing:
    stc
    ret
ReadPassFromFile ENDP

;--------------------------------------------------------------
; writes the password buffer to the file
;--------------------------------------------------------------
savePassToFile PROC
    mov edx, OFFSET fileName
    call CreateOutputFile
    mov fileHandle, eax

    mov edx, OFFSET password
    mov ecx, sizeString
    call WriteToFile

    mov eax, fileHandle
    call CloseFile
    ret
savePassToFile ENDP

;--------------------------------------------------------------
; keeps asking for a password until it has a digit, a symbol
; and an uppercase letter
;--------------------------------------------------------------
askAndValidatePassword PROC
    LOCAL digitFlag:byte, symbolFlag:byte, upperFlag:byte, checkFlag:byte

    mov checkFlag, 0

inputPassword:
    mov eax, 0Bh
    call SetTextColor
    mov edx, OFFSET asknewpassword
    call WriteString
    mov eax, 0Fh
    call SetTextColor
    mov edx, OFFSET password
    mov ecx, 19
    call ReadString
    mov sizeString, eax

    mov esi, OFFSET password
    mov ecx, sizeString
    mov digitFlag, 0
    mov symbolFlag, 0
    mov upperFlag, 0

validateLoop:
    lodsb
    cmp al, 0
    je stringEnd

    cmp al, '0'
    jb checkSymbols
    cmp al, '9'
    ja checkSymbols
    mov digitFlag, 1
    jmp next

checkSymbols:
    cmp al, ' '
    jb next
    cmp al, '/'
    jle incrementForSymbol

    cmp al, ':'
    jb next
    cmp al, '@'
    jle incrementForSymbol

    cmp al, '['
    jb checkCapital
    cmp al, '`'
    jle incrementForSymbol
    jmp checkCapital

incrementForSymbol:
    mov symbolFlag, 1
    jmp next

checkCapital:
    cmp al, 'A'
    jb next
    cmp al, 'Z'
    ja next
    mov upperFlag, 1

next:
    loop validateLoop

stringEnd:
    cmp digitFlag, 0
    je weakPassword
    cmp symbolFlag, 0
    je weakPassword
    cmp upperFlag, 0
    je weakPassword

    mov checkFlag, 1
    mov eax, 0Ah
    call SetTextColor
    mov edx, OFFSET strongPassMsg
    call WriteString
    jmp finish

weakPassword:
    mov eax, 0Eh
    call SetTextColor
    mov edx, OFFSET weakPassMsg
    call WriteString

finish:
    mov eax, 0Fh
    call SetTextColor
    call crlf
    call crlf

    cmp checkFlag, 1
    jne inputPassword

    ret
askAndValidatePassword ENDP

;--------------------------------------------------------------
; rotates each byte of the password left by key bits
;--------------------------------------------------------------
Encrypt PROC
    LOCAL temp:dword

    mov ecx, sizeString
    mov esi, OFFSET password

encryptLoop:
    mov temp, ecx
    movzx ecx, key
    rol byte ptr [esi], cl
    inc esi
    mov ecx, temp
    loop encryptLoop
    ret
Encrypt ENDP

;--------------------------------------------------------------
; undoes the rotate on the saved password then compares it
; with what the user types in
;--------------------------------------------------------------
decryptAndCompare PROC
    LOCAL temp:dword

    mov ecx, sizeString
    mov esi, OFFSET password

decryptLoop:
    mov temp, ecx
    movzx ecx, key
    ror byte ptr [esi], cl
    inc esi
    mov ecx, temp
    loop decryptLoop

    call crlf
    mov eax, 0Bh
    call SetTextColor
    mov edx, OFFSET Askpassword
    call WriteString
    mov eax, 0Fh
    call SetTextColor
    mov edx, OFFSET pass
    mov ecx, 19
    call ReadString

    invoke Str_compare, ADDR pass, ADDR password
    je PasswordAccepted
    jmp PasswordDenied

PasswordAccepted:
    mov eax, 0Ah
    call SetTextColor
    mov edx, OFFSET validPass
    jmp Endfunc

PasswordDenied:
    mov eax, 0Ch
    call SetTextColor
    mov edx, OFFSET invalidPass

Endfunc:
    mov al, 7
    call WriteChar
    call crlf
    call WriteString

    mov eax, 800
    call Delay
    mov al, '.'
    call WriteChar

    mov eax, 800
    call Delay
    mov al, '.'
    call WriteChar

    mov eax, 800
    call Delay
    mov al, '.'
    call WriteChar

    ret
decryptAndCompare ENDP

end main
