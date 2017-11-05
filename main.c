/**
 * @sakaijun
 * C-Version
 *
 * calculate 2 Matrices +,-,*
 * declare 2 dim arrays and create structs
 * init empty pointer array => copy arrays with x,y length information into structs
 * use Matrix struct for calculation  
 */

#include "matStruct.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>


MATRIX generateMat(int row, int col, int arr[row][col]){
	struct MATRIX arr2d;
	arr2d.arr = malloc(row*sizeof(*arr2d.arr));
	for (int i=0; i < row ;i++){
		arr2d.arr[i] = malloc(col*sizeof(*arr2d.arr));
		for (int j=0; j < col ;j++){
			arr2d.arr[i][j] = arr[i][j];
		}
	}
	arr2d.row = row;
	arr2d.col = col;
	return arr2d;
}

int main(void){

	
	int rcA[2];
	int rcB[2];
	char *rcInfo[] = {"rows", "columns"};
	MATRIX matAStruct;
	MATRIX matBStruct;
	MATRIX matResStruct;
	char op;	
	
    for(int i =0; i < sizeof(rcA)/sizeof(rcA[0]); i++){
		printf("Enter number of %s of MatA: ", rcInfo[i]);
        scanf("%d", &rcA[i]);
    }
	
	int matA[rcA[0]][rcA[1]];

    printf("Enter Matrix values:\n");
    for(int i =0; i < rcA[0]; i++){
		for(int j =0; j < rcA[1]; j++){
			printf("a%d%d: ", i,j);							
			scanf("%d", &matA[i][j]);			
		}
	}

	matAStruct = generateMat(rcA[0], rcA[1], matA);
	printRes(matAStruct);

	for(int i =0; i < sizeof(rcB)/sizeof(rcB[0]); i++){
		printf("Enter number of %s of MatB: ", rcInfo[i]);
        scanf("%d", &rcB[i]);
    }
	
	int matB[rcB[0]][rcB[1]];

    printf("Enter Matrix values:\n");
    for(int i =0; i < rcB[0]; i++){
		for(int j =0; j < rcB[1]; j++){
			printf("a%d%d: ", i,j);							
			scanf("%d", &matB[i][j]);			
		}
	}

	matBStruct = generateMat(rcB[0], rcB[1], matB);	
	printRes(matBStruct);

	printf("Select operation +,- or *:\n");	
	scanf("\n%c", &op);
	
	if(op == '+'){
		matResStruct = matrixAddSub('+',matAStruct, matBStruct);
	}else if(op == '-'){
		matResStruct = matrixAddSub('-',matAStruct, matBStruct);
	}else{
		matResStruct = matrixMult(matAStruct,matBStruct);	
	}
	
	printRes(matResStruct);

}
