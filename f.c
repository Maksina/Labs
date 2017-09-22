#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "functions.h"

int *f(int *a, int *b, int n1, int n2, int m1, int m2){ // Функция возвращает подматрицу
	srand(time(NULL));
	int x1,x2;
	int i1,j1,k1,k2;
	x1 = n1 - m1;	//Предельное значение строк
	x2 = n2 - m2;	//Предельное значение столбцов
	if (x1 == 0){
		k1 = 0;
	}else {k1 = rand()%x1;} //произвольное место для начала области (строки)
	if (x2 == 0){
		k2 = 0;
	}else {k2 = rand()%x2;} //произвольное место для начала области	(столбцы)
	
	for (int i=0; i < m1; i++){
		for (int j=0; j < m2; j++){
			i1=i+k1;
			j1=j+k2;
			*(b+i*m2+j) = *(a+i1*n2+j1);
		}
	}
	return b;
}