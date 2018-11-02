#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

int cf58(int *pit);
int cf59(int **ppt, int i);
void cf510(int matrix[][5], int line[], int i);

int main() {
	int data[3][5] = { 
		{1, 2, 3, 4, 5},
		{11, 12, 13, 14, 15},
	    {101, 102, 103, 104, 105} 
	};

	int *p[3] = { data[0], data[1], data[2] };
	int row[5];
	int i;

	printf( "%d\n", cf58(data[0]) );		//����cf58
	printf( "%d\n", cf59(p, 2) );			//����cf59
	cf510(data, row, 0);					//����cf510
	
	for (i = 0; i < 5; i++) {
		printf("% - 4d", row[i]);
	}
	printf("\n");

	system("pause");

	return 0;
}

int cf58(int *pit) {
	int s = 0;

	s += *(pit++);			//�ۼӵ�0��Ԫ��ֵ����ָ����һ��Ԫ��
	s += *(++pit);			//�ۼӵ�2��Ԫ��ֵ
	s += (*pit)++;			//�ۼӵڶ���Ԫ��ֵ���ڶ���Ԫ��ֵ��1
	s += ++(*pit);			//�ڶ���Ԫ��ֵ��1�����ۼ�

	return s;
}

int cf59(int **ppt, int i) {
	int s = 0;

	s += * ( *ppt + i );			//ppt[0][i]
	s += * ( * (ppt + i) );			//ppt[i][0]

	return s;
}

void cf510(int matrix[][5], int line[], int i) {
	int j;
	for (j = 0; j < 5; j++) {
		line[j] = matrix[i][j];
	}

	return;
}