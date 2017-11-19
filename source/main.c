#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "functions.h"

void *f(int *SourceMat, int *FinalMat, int SourceMatLine, int SourceMatColumn, int FinalMatLine, int FinalMatColumn, int IndxL, int IndxC);
void printArr (int *mas, int SourceMatLine, int SourceMatColumn);
void HandMatrix();
void GenMatrix ();

int main() {
	int key;
	do {
		int answ = 0;
		printf("1:Random matrix\n");
		printf("0:Manual input matrix\n");	
		scanf("%d", &answ);
		if (answ == 1) {
			GenMatrix(); // Генерирование массива
		}else {	
			HandMatrix();//Ввод матрицы вручную
		}
		
		printf ("\nRepeat? 1 - YES, 0 - NO\n");
		scanf("%d", &key);

	} while (key == 1); //условие повторения программы
	return 0;
}