#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>

#pragma warning(disable:4996)
#pragma warning(disable:4013)

int main() {

	//------------------S3Q44---------------------------//
	printf("//------------------S3Q44---------------------------//\n\n");
	unsigned u1;
	char buffer[100];

	printf("请输入一个正整数:");
	scanf("%u", &u1);

	_asm {
			push	0
			push	4
			push	16
			lea		edx, buffer
			push	edx
			mov		eax, u1
			push	eax
			call	Convert_num_2_str
			add		esp, 20
	}

	printf("输入的正整数为%s\n\n", buffer);

	//------------------S3Q45---------------------------//
	getchar();
	printf("//------------------S3Q45---------------------------//\n\n");
	char c1;
	char str_10_bit[100], str_2_bit[100], str_16_bit[100];
	printf("输入一个字符:");
	scanf("%c", &c1);
	
	_asm {
			push	0
			push	1
			push	10
			lea		edx, str_10_bit
			push	edx
			movzx	eax, c1
			push	eax
			call	Convert_num_2_str
			add		esp, 20

			push	0
			push	1
			push	2
			lea		edx, str_2_bit
			push	edx
			movzx	eax, c1
			push	eax
			call	Convert_num_2_str
			add		esp, 20

			push	0
			push	1
			push	16
			lea		edx, str_16_bit
			push	edx
			movzx	eax, c1
			push	eax
			call	Convert_num_2_str
			add		esp, 20
	}

	printf("10进制字符串:%s\n", str_10_bit);
	printf("2进制字符串:%s\n", str_2_bit);
	printf("16进制字符串:%s\n", str_16_bit);

	//------------------S3Q50---------------------------//
	getchar();
	printf("//------------------S3Q50---------------------------//\n\n");
	unsigned u2, u3;
	char str_of_addResult[100], str_of_subResult[100], str_of_mulResult[100];
	printf("输入两个自然数:");
	scanf("%u %u", &u2, &u3);

	_asm {
			mov		eax, u2
			mov		ecx, u3

			add		eax, ecx

			push	0						
			push	4
			push	10
			lea		edx, str_of_addResult
			push	edx
			push	eax
			call	Convert_num_2_str
			add		esp, 20

			mov		eax, u2
			mov		ecx, u3

			sub		eax, ecx
			push	1						
			push	4
			push	10
			lea		edx, str_of_subResult
			push	edx
			push	eax
			call	Convert_num_2_str
			add		esp, 20

			mov		eax, u2
			mov		ecx, u3

			mul		ecx

			push	0
			push	4
			push	10
			lea		edx, str_of_mulResult
			push	edx
			push	eax
			call	Convert_num_2_str
			add		esp, 20

	}

	printf("%u + %u = %s\n", u2, u3, str_of_addResult);
	printf("%u - %u = %s\n", u2, u3, str_of_subResult);
	printf("%u * %u = %s\n", u2, u3, str_of_mulResult);

	//------------------S3Q51---------------------------//
	getchar();
	printf("//------------------S3Q51---------------------------//\n\n");
	unsigned u4, u5;
	char str_of_divResult[100], str_of_remainResult[100];
	printf("输入两个自然数:");
	scanf("%u %u", &u4, &u5);

	_asm {
		mov		eax, u4
		mov		ecx, u5

		cdq
		div		ecx
		push	edx

		push	0
		push	4
		push	10
		lea		esi, str_of_divResult
		push	esi
		push	eax
		call	Convert_num_2_str
		add		esp, 20

		pop		edx
		push	0
		push	4
		push	10
		lea		esi, str_of_remainResult
		push	esi
		push	edx
		call	Convert_num_2_str
		add		esp, 20
	}

	printf("%u / %u = %s\n", u4, u5, str_of_divResult);
	printf("%u %% %u = %s\n", u4, u5, str_of_remainResult);

	//------------------S4Q24---------------------------//
	getchar();
	printf("//------------------S4Q24---------------------------//\n\n");
	int n1, n2;
	char str_16_input1[100], str_16_input2[100];
	char str_16_add_output[100], str_16_sub_output[100];
	printf("输入两个16进制字符串:");
	scanf("%s %s", str_16_input1, str_16_input2);

	_asm {
			lea		eax, str_16_input1
			push	16
			push	eax
			call	convert_str_2_num
			add		esp, 8
			mov		n1, eax

			lea		eax, str_16_input2
			push	16
			push	eax
			call	convert_str_2_num
			add		esp, 8
			mov		n2, eax

			mov		ecx, n1
			add		ecx, eax

			push	0
			push	4
			push	16
			lea		esi, str_16_add_output
			push	esi
			push	ecx
			call	Convert_num_2_str
			add		esp, 20

			mov		ecx, n1
			mov		eax, n2
			sub		ecx, eax

			push	0
			push	4
			push	16
			lea		esi, str_16_sub_output
			push	esi
			push	ecx
			call	Convert_num_2_str
			add		esp, 20

	}

	printf("%d + %d = %sH\n", n1, n2, str_16_add_output);
	printf("%d - %d = %sH\n", n1, n2, str_16_sub_output);

	//------------------S4Q25---------------------------//
	getchar();
	printf("//------------------S4Q25---------------------------//\n\n");
	int integer[4];
	int num_of_1;
	printf("请输入四个整数:");
	for (int i = 0; i < 4; i++) {
		scanf("%d", integer + i);
	}

	_asm {
			lea		esi, integer
			xor		ecx, ecx
			xor		edx, edx
		TL2lty025:
			cmp		ecx, 4
			je		TN1lty025
			lea		eax, [esi + ecx * 4]
			mov		eax, [eax]
			xor		edi, edi
		TL1lty025:
			cmp		edi, 32
			je		TN2lty025
			bt		eax, edi
			jnc		TN3lty025
			inc		edx
		TN3lty025:
			inc		edi
			jmp		TL1lty025
		TN2lty025:
			inc		ecx
			jmp		TL2lty025
		TN1lty025:
			mov		num_of_1, edx
	}

	for (int i = 0; i < 4; i++) {
		printf("%08X", integer[i]);
	}
	printf("中1的个数为:%d\n\n", num_of_1);

	//------------------S4Q26---------------------------//
	getchar();
	printf("//------------------S4Q26---------------------------//\n\n");

	char bit_string[100];
	printf("请输入一个字符串:");
	scanf("%s", bit_string);
	int longest_len_of_0;

	_asm {
			lea		esi, bit_string
			mov		edx, 1			//flag
			xor		edi, edi
		TL2lty026:
			cmp		BYTE PTR [esi], 0
			je		TN1lty026
			lodsb 
			cbw
			xor		cx, cx
		TL1lty026:
			cmp		cx, 8
			je		TN2lty026
			bt		ax, cx
			jc		TN3lty026		
			cmp		edx, 0			//bit = 0
			je		TN4lty026
			mov		ebx, 1
			jmp		TN5lty026
		TN4lty026:
			inc		ebx
		TN5lty026:
			mov		edx, 0
			jmp		TN7lty026
		TN3lty026:
			cmp		edx, 1
			je		TN6lty026
			cmp		edi, ebx
			ja		TN6lty026
			mov		edi, ebx
		TN6lty026:
			mov		edx, 1
		TN7lty026:
			inc		cx
			jmp		TL1lty026
		TN2lty026:
			jmp		TL2lty026
		TN1lty026:
			mov		longest_len_of_0, edi
	}

	printf("位串连续为0的最大长度:%d\n", longest_len_of_0);

	system("pause");

	return 0;

	_asm {
		Convert_num_2_str:
			push	ebp
			mov		ebp, esp
			push	ebx
			push	esi
			push	edi									//建立堆栈框架
			
			mov		eax, dword ptr[ebp + 16]			//system
			cmp		eax, 2
			je		TN3ltyfx01_CASE2
			cmp		eax, 10
			je		TN5ltyfx01_CASE10
			cmp		eax, 16
			je		TN6ltyfx01_CASE16
			jmp		TN1ltyfx01_Default
		
		TN3ltyfx01_CASE2:
			mov		edi, dword ptr[ebp + 8]				//num
			mov		edx, dword ptr[ebp + 12]			//buffer
			mov		ebx, dword ptr[ebp + 20]			//size
			xor		esi, esi
			inc		esi
			shl		ebx, 3								//size * 8(位数)
		TL31ltyfx01:
			mov		ecx, ebx							// ecx = size * 8				
			sub		ecx, esi
			mov		eax, edi
			shr		eax, cl
			and		al, 1
			add		al, 48
			mov		byte ptr[edx], al
			inc		edx
			;
			inc		esi
			cmp		esi, ebx
			jle		SHORT TL31ltyfx01
			mov		byte ptr[edx], 0
			mov		eax, 1
			jmp		TN4ltyfx01_RET
		
		TN5ltyfx01_CASE10:
			xor		esi, esi
			mov		edi, dword ptr[ebp + 12]		//buffer
			mov		eax, dword ptr [ebp + 8]		//num
			mov		ebx, dword ptr[ebp + 24]		//sign
			cmp		ebx, 0
			je		TN53ltyfx01
			test	eax, eax
			jns		TN53ltyfx01
			mov		byte ptr [edi], 45
			inc		edi
			neg		eax
			//inc		eax
		TN53ltyfx01:
			cdq
			mov		ebx, 10
		TL51ltyfx01:
			div		ebx
			add		edx, 48
			push	edx
			inc		esi
			cmp		eax, 0
			je		TN51ltyfx01
			cdq
			jmp		TL51ltyfx01
		TN51ltyfx01:
			
		TL52ltyfx01:
			cmp		esi, 0
			je		TN52ltyfx01
			pop		ecx
			mov		byte ptr[edi], cl
			inc		edi
			dec		esi
			jmp		TL52ltyfx01
		TN52ltyfx01:
			mov		byte ptr[edi], 0
			mov		eax, 1
			jmp		TN4ltyfx01_RET

		TN6ltyfx01_CASE16:
			xor		esi, esi
			mov		edi, dword ptr [ebp + 8]		//num
			inc		esi
			mov		edx, dword ptr [ebp + 12]		//buffer
			mov		ebx, dword ptr[ebp + 20]		//size
			shl		ebx, 1							//size * 2
		TL61ltyfx01:
			mov		ecx, ebx
			sub		ecx, esi
			shl		ecx, 2
			mov		eax, edi
			shr		eax, cl
			and		al, 15
			add		al, 48
			cmp		al, 57
			jle		SHORT TN61ltyfx01
			add		al, 7
		TN61ltyfx01:
			mov		byte ptr[edx], al
			inc		edx
			;
			inc		esi
			cmp		esi, ebx
			jle		SHORT TL61ltyfx01
			mov		byte ptr[edx], 0
			mov		eax, 1
			jmp		TN4ltyfx01_RET

		TN1ltyfx01_Default:
			mov		eax, 0
		TN4ltyfx01_RET:
			pop		edi
			pop		esi
			pop		ebx
			pop		ebp
			ret
	}

	_asm {
		convert_str_2_num:
			push	ebp
			mov		ebp, esp
			push	ebx
			push	esi
			push	edi									//建立堆栈框架

			mov		esi, dword ptr [ebp + 8]			//buffer
			mov		edi, dword ptr [ebp + 12]			//system
			mov		ecx, 1
			xor		edx, edx
			xor		ebx, ebx

		TL1ltyfx02:
			cmp		[esi], 0
			je		TN3ltyfx02_toNUM
			lodsb	
			sub		al, 48
			cmp		al, 9
			jbe		TN2ltyfx02
			sub		al, 7
			cmp		al, 15
			jbe		TN2ltyfx02
			sub		al, 32
		TN2ltyfx02:
			movzx	eax, al
			push	eax
			inc		ebx
			jmp		TL1ltyfx02

		TN3ltyfx02_toNUM:
			cmp		ebx, 0
			je		TN1ltyfx02_RET
			pop		eax
			imul	eax, ecx
			imul	ecx, edi
			add		edx, eax
			dec		ebx
			jmp		TN3ltyfx02_toNUM

		TN1ltyfx02_RET :
			mov		eax, edx
			pop		edi
			pop		esi
			pop		ebx
			pop		ebp
			ret
	}
}