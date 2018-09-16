#include<stdio.h>
#include<stdlib.h>

int vari = 0x12345678;
char buff[] = "ABCDE";

int main() {
	printf("Part_1\n");
	int varx = 0x11223344, vary = 0;
	//«∂»Îª„±‡
	_asm {
		MOV EAX, varx
		MOV AX, 5566H
		MOV AL, 77H
		MOV vary, EAX
	}
	printf("vary = %08XH\n", vary);

	printf("Part_2\n");
	unsigned char flag1, flag2, flag3;
	;
	_asm {
		MOV AH, 0
		SAHF
		LAHF
		MOV flag1, AH
		;
		MOV DX, 7799H
		ADD DL, DH
        LAHF
		MOV flag2, AH
        ;
		SUB DH, 84H
		CLC
		LAHF
		MOV flag3, AH
	}
	printf("flag1 = %02XH\n", flag1);
	printf("flag2 = %02XH\n", flag2);
	printf("flag3 = %02XH\n", flag3);

	printf("Part_3\n");
	
	int dv1, dv2, dv3, dv4;
	_asm {
		LEA EBX, vari
		MOV EAX, [EBX]
		MOV dv1, EAX
		MOV EAX, [EBX + 1]
		MOV dv2, EAX
		;
		MOV ECX, 2
		MOV AX, [EBX+ECX]
		MOV dv3, EAX
		;
		MOV AL, [EBX + ECX*2 + 3]
        MOV dv4, EAX
	}
	printf("dv1 = %08XH\n", dv1);
	printf("dv2 = %08XH\n", dv2);
	printf("dv3 = %08XH\n", dv3);
	printf("dv4 = %08XH\n", dv4);

	system("pause");
	return 0;
}