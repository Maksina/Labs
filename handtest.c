#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "functions.h"


void HandMatrix(){
	int FinalMatLine = 0;
	int FinalMatColumn = 0;
	int SourceMatLine = 0;
	int SourceMatColumn = 0;
	int IndxL,IndxC;
	int *FinalMat,*SourceMat;
	printf("Enter size: \n");
	printf("Line:");
	scanf("%d", &SourceMatLine); // Объявляем колличество строк
	printf("Column:");
	scanf("%d", &SourceMatColumn); // Объявляем колличество столбцов
	SourceMat = (int*)malloc(SourceMatColumn*SourceMatLine*sizeof(int)); //Выделение памяти под исходный массив
	printf ("Input matrix:\n");
	for (int i = 0; i < SourceMatLine; i++){ //ввод матрицы
		for	(int j = 0; j < SourceMatColumn; j++) {
		printf("SourceMat[%d][%d]=",i,j);
		scanf("%d", (SourceMat+i*SourceMatColumn+j));
		}
	}
	printArr(SourceMat,SourceMatLine,SourceMatColumn);

	printf("\nEnter size of area: lines=");
	scanf("%d", &FinalMatLine); // Объявляем размер массива
	printf("\nEnter size of area: columns=");
	scanf("%d", &FinalMatColumn); // Объявляем размер массива

	while ((FinalMatLine > SourceMatLine) || (FinalMatColumn>SourceMatColumn) || (FinalMatColumn == 0) || (FinalMatLine == 0)) { //обработка ошибки при размере области большей, чем матрицы
		printf("ERROR, m>n\n");
		printf("\nEnter size of area: lines=");
		scanf("%d", &FinalMatLine); // Объявляем размер массива
		printf("\nEnter size of area: columns=");
		scanf("%d", &FinalMatColumn); // Объявляем размер массива
	}
	FinalMat = (int*)malloc(FinalMatLine*FinalMatColumn*sizeof(int)); //Выделение памяти под новый массив
	if ((SourceMatLine == FinalMatLine) && (SourceMatColumn == FinalMatColumn)) {  // обработка случая равненства матрицы и области
		printArr(SourceMat,SourceMatLine,SourceMatColumn);	
	}else {
		printf("\nEnter index for start area: line=");
		scanf("%d", &IndxL); // Индекс по строкам для старта области
		printf("\nEnter index for start area: column=");
		scanf("%d", &IndxC); // Индекс по столбцам для старта области
		f(SourceMat,FinalMat,SourceMatLine,SourceMatColumn,FinalMatLine,FinalMatColumn,IndxL,IndxC);
		printArr(FinalMat,FinalMatLine,FinalMatColumn);
	}	

	free(SourceMat);
	free(FinalMat);
	return;

}