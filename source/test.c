#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "functions.h"

void GenMatrix (){
	int *FinalMat,*SourceMat;
	int SourceMatLine,SourceMatColumn,IndxL,IndxC,FinalMatLine,FinalMatColumn,x1,x2;
	SourceMatLine = rand()%10+2; //размеры матрицы от 2 до 10
	SourceMatColumn = rand()%10+2;
	SourceMat = (int*)malloc(SourceMatColumn*SourceMatLine*sizeof(int)); //Выделение памяти под исходный массив
	srand(time(NULL));
	for (int i = 0; i < SourceMatLine; i++){ //ввод матрицы
		for	(int j = 0; j < SourceMatColumn; j++) {
		*(SourceMat+i*SourceMatColumn+j) = rand()%10;
		}
	}
	printArr(SourceMat,SourceMatLine,SourceMatColumn); // Вывод матрицы
	for (int j = 0; j <= 1; j++){
		FinalMatLine = rand()%SourceMatLine;
		if (FinalMatLine == 0){
			FinalMatLine = 1;
		}
		FinalMatColumn = rand()%SourceMatColumn;
		if (FinalMatColumn == 0){
			FinalMatColumn = 1;
		}
		x1 = SourceMatLine - FinalMatLine ;	//Предельное значение строк
		x2 = SourceMatColumn - FinalMatColumn ;	//Предельное значение столбцов
		IndxL = rand()%x1+1; //произвольное место для начала области (строки)
		IndxC = rand()%x2+1; //произвольное место для начала области	(столбцы)
		FinalMat = (int*)malloc(FinalMatColumn*FinalMatLine*sizeof(int));
		f(SourceMat,FinalMat,SourceMatLine,SourceMatColumn,FinalMatLine,FinalMatColumn,IndxL,IndxC);
		printArr(FinalMat,FinalMatLine,FinalMatColumn);
		free(FinalMat);
	}
	
	return;
}

