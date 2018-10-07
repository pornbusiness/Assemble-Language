#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>

#pragma warning(disable:4996)
#pragma warning(disable:4013)

char punc_ASCLL[] = { 33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63 };

int main() {

	/*------------------------question 18---------------------------*/
	printf("----Question 18-----\n\n");
	char string1a[100], string1b[100], string1c[200];
	printf("请输入字符串1：");
	gets(string1a);
	printf("请输入字符串2：");
	gets(string1b);

	_asm {
			lea			esi, string1a
			lea			edi, string1c
		TL1lty018:/*拷贝字符串1*/
			cmp			[esi], 0
			je			TN1lty018
			movsb		
			jmp			TL1lty018
		TN1lty018:/*字符串1拷贝完成*/
			lea			esi, string1b
			;
		TL2lty018:/*拷贝字符串2*/
			cmp			[esi], 0
			je			TN2lty018
			movsb
			jmp			TL2lty018
		TN2lty018:/*字符串2拷贝完成*/
			
			mov			byte ptr [edi], 0  //末尾添加'/0'
	}

	printf("the string after concat:%s\n\n", string1c);

	/*------------------------question 19---------------------------*/
	printf("----Question 19-----\n\n");
	char string2a[100], string2b[100];
	printf("请输入一个字符串：");
	gets(string2a);

	_asm {
			lea			esi, string2a
			lea			edi, string2b

		TL2lty019:/*遍历字符串*/
			cmp			[esi], 0
			je			TN4lty019_END_OF_STR
			lodsb	
			push		eax
			call		whetherPuncMark
			test		eax, eax
			jnz			TN5lty019_IS_PUNC
			pop			eax
			stosb
			jmp			TN6lty019
		TN5lty019_IS_PUNC:
			add			esp, 4
		TN6lty019:
			jmp			TL2lty019

		TN4lty019_END_OF_STR:
			mov			byte ptr [edi], 0
	}

	printf("the string after filtering punctuation marks:%s\n\n", string2b);

	/*------------------------question 22---------------------------*/
	printf("----Question 22-----\n\n");

	char stra[100];
	char c;
	int n;
	printf("请输入一个字符和一个数字：");
	scanf("%c %d", &c, &n);
	_asm {
		mov		ecx, n
		movzx	eax, c
		lea		edi, stra
		rep		stosb
		mov		byte ptr[edi], 0
	}

	printf("%s\n", stra);
	

	system("pause");
	return 0;

	_asm {
		whetherPuncMark:
			push		ebp
			mov			ebp, esp
			push		esi
			push		edi
			push		ebx
			;
			lea			edi, punc_ASCLL
			mov			al, [ebp+8]

		TL1lty019:/*判断是否为标点符号*/
			cmp			[edi], 0
			je			TN1lty019_NOT_FOUND
			scasb 
			jz			TN2lty019_FOUND
			jmp			TL1lty019

		TN1lty019_NOT_FOUND:/*不是标点符号*/
			mov			eax, 0
			jmp			SHORT TN3lty019_OVER
		TN2lty019_FOUND:/*是标点符号*/
			mov			eax, 1
		
		TN3lty019_OVER:
			pop			ebx
			pop			edi
			pop			esi
			pop			ebp
			ret
	}

	
}