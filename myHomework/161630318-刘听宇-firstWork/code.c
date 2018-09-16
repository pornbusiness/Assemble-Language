#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

char buff[10];
char char_input[100];

int main() {
	int varx, vary, gtr;
	unsigned int abv;
	int sub_result;
	printf("part_1\n");
	printf("input:");
	scanf("%d %d", &varx, &vary);

	_asm {
			MOV EAX, varx
			MOV EBX, vary
			MOV ECX, EAX
			SUB ECX, EBX
			JG L2
			MOV gtr, EBX
			JMP NEXT1
		 L2:
			MOV gtr, EAX
	   NEXT1:
			JA L3
			MOV abv, EBX
			JMP NEXT2
		 L3:
			MOV abv, EAX
	  NEXT2:
			JNS L1
			NEG ECX
		 L1:
			MOV sub_result, ECX
	}

	printf("|varx - vary| = %d\n", sub_result);
	printf("有符号数较大值：%d\n", gtr);
	printf("无符号数较大值：%u\n", abv);

	printf("part_2\n");
	printf("input:");
	getchar();
	for (int i = 0; i < 4; i++) {
		scanf("%c", buff + i);
	}
	short word_1, word_2;
	int dword_;
	_asm {
		LEA EAX, buff
		XOR EBX, EBX
		MOV BX, WORD PTR [EAX]
		MOV word_1, BX
		MOV BX, WORD PTR [EAX+2]
		MOV word_2, BX
		MOV EBX, DWORD PTR [EAX]
		MOV dword_, EBX
	}
	printf("word_1 = %04XH\n", word_1);
	printf("word_2 = %04XH\n", word_2);
	printf("dword = %08XH\n", dword_);

	printf("part_3\n");
	printf("input:");
	scanf("%s", char_input);
	int len;
	_asm {
		LEA EAX, char_input
		XOR EDX, EDX
     LP:
		MOV EBX, [EAX+EDX]
		TEST EBX, EBX
		JZ NEXT
		INC EDX
		JMP LP
   NEXT:
		MOV len, EDX 
	}
	printf("the length of the string：%d\n", len);

	system("pause");
	return 0;
}