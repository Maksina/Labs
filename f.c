#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "functions.h"

void *f(int *SourceMat, int *FinalMat, int SourceMatLine, int SourceMatColumn, int FinalMatLine, int FinalMatColumn, int k1, int k2){ // Функция возвращает подматрицу
	srand(time(NULL));
	int i1,j1;
	for (int i=0; i < FinalMatLine; i++){	//Цикл выделения заданную область в новую матрицу
		for (int j=0; j < FinalMatColumn; j++){
			i1=i+k1;
			j1=j+k2;
			*(FinalMat+i*FinalMatColumn+j) = *(SourceMat+i1*SourceMatColumn+j1);
		}
	}
	return FinalMat;
}