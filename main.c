#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "functions.h"

int *f(int *a, int *b, int n1, int n2, int m1, int m2);

void printArr (int *mas, int n1, int n2);

int main() {
	int key;
	do {
		int *a;
		int *b;
		int n1 = 0;
		int n2 = 0;
		int m1 = 0;
		int m2 = 0;

		printf("Enter size: \n");
		printf("Line:");
		scanf("%d", &n1); // Объявляем колличество строк
		printf("Column:");
		scanf("%d", &n2); // Объявляем колличество столбцов
		a = (int*)malloc(n2*n1*sizeof(int)); //Выделение памяти под исходный массив
		printf ("Input matrix:\n");
		for (int i = 0; i < n1; i++){ //ввод матрицы
			for	(int j = 0; j < n2; j++) {
				printf("a[%d][%d]=",i,j);
				scanf("%d", (a+i*n2+j));
			}
		}
		printArr(a,n1,n2);
		printf("\nEnter size of area: line=");
		scanf("%d", &m1); // Объявляем размер массива
		printf("\nEnter size of area: column=");
		scanf("%d", &m2); // Объявляем размер массива

		while ((m1 > n1) || (m2>n2) || (m2 == 0) || (m1 == 0)) { //обработка ошибки при размере области большей, чем матрицы
			printf("ERROR, m>n\n");
			printf("\nEnter size of area: line=");
			scanf("%d", &m1); // Объявляем размер массива
			printf("\nEnter size of area: column=");
			scanf("%d", &m2); // Объявляем размер массива
		}
		b = (int*)malloc(m1*m2*sizeof(int)); //Выделение памяти под новый массив
		if ((n1 == m2) && (n2 ==m2)) {  // обработка случая равненства матрицы и области
			printArr(a,n1,n2);	
		}else {
			int *c = f(a,b,n1,n2,m1,m2);
			printArr(c,m1,m2);
		}	
		printf ("\nRepeat? 1 - YES, 0 - NO\n");
		scanf("%d", &key);
		free(a);
		free(b);
		n1 = 0;
		n2 = 0;
		m2 = 0;
		m1 = 0;
	} while (key == 1); //условие повторения программы
	return 0;
}