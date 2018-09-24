#include<stdio.h>
#include<stdlib.h>

int main() {
	//--------------------------------------------------------------------------------------
	char buffx[11] = { 1,1,1,1,1,1,1,128,1,1 };
	char buffy[21] = { 1,2,3,128,5,6,7,128,9,10,11,128,13,14,15,128,17,128,19,20 };
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
	printf("|sum_odd:%d - sum_even:%d| = %d\n", sum_odd, sum_even, sub_result);


	system("pause");
	return 0;
}