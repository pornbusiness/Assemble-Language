.386
.model flat,stdcall
option casemap:none

includelib msvcrt.lib

printf proto C:VARARG

.data
msg db "Hello World!",
0dh, 0ah, 0

.code
start:
call main
ret
main proc

push offset msg
call printf
add esp, 4
ret

main endp

end start