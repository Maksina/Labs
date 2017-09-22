#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "functions.h"

void printArr (int *mas, int n1, int n2){
	printf("Matrix:\n");
	for (int i=0; i < n1; i++) { //Вывод матрицы
		for (int j=0; j < n2; j++) {
			printf("%5d ", *(mas+i*n2+j));
		}
	printf("\n");
	}
	return;
}