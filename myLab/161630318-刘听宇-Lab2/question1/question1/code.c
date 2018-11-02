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

	printf( "%d\n", cf58(data[0]) );		//调用cf58
	printf( "%d\n", cf59(p, 2) );			//调用cf59
	cf510(data, row, 0);					//调用cf510
	
	for (i = 0; i < 5; i++) {
		printf("% - 4d", row[i]);
	}
	printf("\n");

	system("pause");

	return 0;
}

int cf58(int *pit) {
	int s = 0;

	s += *(pit++);			//累加第0个元素值，并指向下一个元素
	s += *(++pit);			//累加第2个元素值
	s += (*pit)++;			//累加第二个元素值，第二个元素值加1
	s += ++(*pit);			//第二个元素值加1，并累加

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