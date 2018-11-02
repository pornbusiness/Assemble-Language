segment text			;命名段text
org     100H			;段内偏移从100H开始计算
;
mov     ax, cs
mov     ds, ax
;
mov     dx, hello
mov     ah, 9
int     21H
;
mov     ah, 4CH
int     21H
;

hello  db  "Hello, World", 0DH, 0AH, '$'