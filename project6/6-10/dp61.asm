segment text			;������text
org     100H			;����ƫ�ƴ�100H��ʼ����
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