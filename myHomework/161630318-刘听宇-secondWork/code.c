#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable:4996)

int main() {
	//--------------------------------------------------------------------------------------
	//char buffx[11] = { 1,1,1,1,1,1,1,128,1,1 };
	char buffy[21] = { 1,2,3,128,5,6,7,128,9,10,11,128,13,14,15,128,17,128,19,20 };
	char buffx[21] = { 255,255,255,255,255,255,255,255,255,255 };
	int num_pos, num_neg, result_s, result_u;
	_asm{
			lea		eax, buffx
			xor		ecx, ecx
		    push	0
			push    0
			push    0
			push	0
		 LP:
			movsx	edx, [eax+ecx]	
			cmp		edx, 0
			jl		NEV
			inc		[esp]
			jmp		NEXT1
	    NEV:
	        inc		[esp+4]
      NEXT1:
			add		[esp+8], edx
			movzx	edx, [eax+ecx]
			add		[esp+12], edx
			inc		ecx
		    cmp		ecx, 9
			jbe		LP
			mov		eax, [esp]
			mov		ecx, [esp+4]
			mov		num_pos, eax
			mov		num_neg, ecx
			mov		eax, [esp+8]
			mov		result_s, eax
			mov		eax, [esp+12]
			mov		result_u, eax
			add		esp, 16
	}
	printf("37&39\n");
	printf("the number of positive = %d\n", num_pos);
	printf("the number of negative = %d\n", num_neg);
	printf("the sum of these 10 signed data = %d\n", result_s);
	printf("the sum of these 10 unsigned data = %d\n\n", result_u);

	//-----------------------------------------------------------------------------------
	int num_pos_16, num_neg_16;
	int num_pos_32, num_neg_32;
	_asm {
			lea		eax, buffy
			xor		ecx, ecx
			push	0
			push    0
			push	0
			push	0
		 LP1:
			mov		dx, [eax+ecx*2]
			cmp		dx, 0
			jl		lab1
			inc		[esp]
			jmp		NEXT
	   lab1:
			inc		[esp+4]
	  NEXT:
			inc		ecx
			cmp		ecx, 9
			jbe		LP1
			mov		edx, [esp]
			mov		num_pos_16, edx
			mov		edx, [esp+4]
			mov		num_neg_16, edx
			;
			xor		ecx, ecx
		LP2:
			mov		edx, [eax+ecx*4]
			cmp		edx, 0
			jl		lab2
			inc		[esp+8]
			jmp		NEXT2
	   lab2:
			inc		[esp+12]
	  NEXT2:
			inc		ecx
			cmp		ecx, 4
			jbe		LP2
			mov		edx, [esp+8]
			mov		num_pos_32, edx
			mov		edx, [esp+12]
			mov		num_neg_32, edx
			add		esp, 16
	}
	printf("38\n");
	printf("the number of positive_16 = %d\n", num_pos_16);
	printf("the number of negative_16 = %d\n", num_neg_16);
	printf("the number of positive_32 = %d\n", num_pos_32);
	printf("the number of negative_32 = %d\n", num_neg_32);

	//---------------------------------------------------------------------------
	int buffz[14] = { 1,3,5,7,9,11,14,2,4,6,8,10,12 };
	int sub_result;
	int sum_odd, sum_even;
	_asm {
			lea		eax, buffz
			xor		ecx, ecx
			push	0
			push	0
		LPT:
			mov		edx, [eax+ecx*4]
			test	edx, 1
			jz		lab1T
			add		[esp], edx
			jmp		NEXTT
	  lab1T:
			add		[esp+4], edx
	  NEXTT:
			inc		ecx
			cmp		ecx, 12
			jbe		LPT
			mov		edx, [esp]
		    mov		sum_odd, edx
			mov		ebx, [esp+4]
			mov		sum_even, ebx
			sub		edx, ebx
			cmp		edx, 0
			jnl		JPT
			neg		edx
		JPT:
			mov		sub_result, edx	
			add     esp, 8
			
	}

	printf("38\n");
	printf("|sum_odd:%d - sum_even:%d| = %d\n\n", sum_odd, sum_even, sub_result);

	//---------------------------------------------------------------------------------
	unsigned input_1, count_0_bit, count_1_bit;
	printf("--------part2------------------\n\n");
	printf("35\n");
	printf("please input a unsigned data:");
	scanf_s("%u", &input_1);

	_asm {
			mov		eax, input_1
			xor		ecx, ecx
			push	0
			push	0
		TL1lty035:
			test	eax, 80000000H
			js		TN1lty035
			inc		[esp]
			jmp		TN2lty035
		TN1lty035:
			inc		[esp+4]
		TN2lty035:
			shl		eax, 1
			inc		ecx
			cmp		ecx, 31
			jbe		TL1lty035
			;
			mov		eax, [esp]
			mov		count_0_bit, eax
			mov		eax, [esp+4]
			mov		count_1_bit, eax
			add		esp, 8
	}

	printf("num of 0 bit = %d\n", count_0_bit);
	printf("num of 1 bit = %d\n", count_1_bit);

	char charac1 = 0, charac2 = 0;
	short data_merge_from_2_character;
	printf("36.\n");
	printf("please input 2 character:");
	getchar();
	scanf("%d%d", &charac1, &charac2);

	_asm {
			xor		edx, edx
			movzx	eax, charac1
			movzx	ebx, charac2
			push	eax
			push	ebx
			xor		ebx, ebx
		TL1lty036:
		    test	edx, 1
			jnz		TN1lty036
			mov		eax, [esp]
			shr		[esp], 1
			jmp		TN2lty036
		TN1lty036:
			mov		eax, [esp+4]
			shr		[esp+4], 1
		TN2lty036:
			and		eax, 1
			xor		esi, esi
		TL2lty036:
			cmp		esi, edx
			jb		TN3lty036
			jmp		TN4lty036
		TN3lty036:
			shl		eax, 1
			inc		esi
			jmp		TL2lty036
		TN4lty036:
			or		ebx, eax
			inc		edx
			cmp		edx, 15
			jbe		TL1lty036
			mov		data_merge_from_2_character, bx
			add		esp, 8
	}

	printf("data merged from character %XH and charcter %XH = %04XH\n", 0xff&charac1, 0xff&charac2, 0xffff&data_merge_from_2_character);

	int int_input_37_1, int_input_37_2;
	printf("37.\n");
	printf("please input 2 int number:");
	scanf("%x%x", &int_input_37_1, &int_input_37_2);

	_asm {
			mov		eax, int_input_37_1
			cmp		eax, 0
			jge		TN1lty037
			neg		eax
		TN1lty037:
			mov		edx, int_input_37_2
			cmp		edx, 0
			jge		TN2lty037
			neg		edx
		TN2lty037:
			mov		cx, dx
			mov		dx, ax
			mov		ax, cx
			;
			mov		int_input_37_1, edx
			mov		int_input_37_2, eax
	}

	printf("after exchange:%08XH, %08XH\n", int_input_37_1, int_input_37_2);


	char string_1[100];
	int num_of_elphabat, num_of_number, num_of_other_type;
	printf("38.\n");
	printf("please input a string:");
	scanf("%s", string_1);
	int num_of_char = strlen(string_1);

	_asm {
			lea		eax, string_1
			mov		ebx, num_of_char
			xor		ecx, ecx
			push	0
			push	0
			push	0
			;
		TL1lty038:
			mov		dl, [eax+ecx]
			cmp		dl, 31H
			jb		TN1lty038
			cmp		dl, 39H
			jbe		TN3lty038
			cmp		dl, 41H
			jb		TN1lty038
			cmp		dl, 5aH
			jbe		TN2lty038
			cmp		dl, 61H
			jb		TN1lty038
			cmp		dl, 7AH
			jbe		TN2lty038
		TN1lty038:
			inc		[esp]
			jmp		TN4lty038
		TN2lty038:
			inc		[esp+4]
			jmp		TN4lty038
		TN3lty038:
			inc		[esp+8]
		TN4lty038:
			inc		ecx
			cmp		ecx, ebx
			jb		TL1lty038
			;
			mov		eax, [esp]
			mov		num_of_other_type, eax
			mov		eax, [esp+4]
			mov		num_of_elphabat, eax
			mov		eax, [esp+8]
			mov		num_of_number, eax
			add		esp, 12
	}

	printf("the num of english elphabat = %d\n", num_of_elphabat);
	printf("the num of number = %d\n", num_of_number);
	printf("the num of other type of character = %d\n", num_of_other_type);

	_asm {
			lea		eax, string_1
			mov		ebx, num_of_char
			xor		esi, esi
			mov		edx, ebx
			dec		edx
		TL1lty039:
			mov		cl, [eax+esi]
			mov		bl, [eax+edx]
			;
			mov		[eax+esi], bl
			mov		[eax+edx], cl
			;
			inc		esi
			dec		edx
			cmp		esi, edx
			jb		TL1lty039
	}

	printf("39.\n");
	printf("the reversed string is:%s\n", string_1);

	system("pause");
	return 0;
}