/**
 * @sakaijun
 * C - Version
 * +,- or * of 2 Matrices
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include "matStruct.h"


void printRes(MATRIX result){	

	for(int r = 0; r <result.row; r++){
		printf("(  ");
		for(int c = 0; c < result.col; c++){
			printf("%4.1d ", result.arr[r][c]);
		}
		
		printf("  )\n");
	}
	printf("\n");

}

MATRIX matrixMult(MATRIX matA, MATRIX matB){

	//required: cols of A === rows of B
	MATRIX resultStruct;
	
	resultStruct.arr = malloc(matA.row*sizeof(*resultStruct.arr));
	for (int i=0; i < matA.row;i++){
		resultStruct.arr[i] = malloc(matA.col*sizeof(*resultStruct.arr));		
	}	

	if(matA.col == matB.row){
		for(int r = 0; r < matA.row; r++){
			for(int c = 0; c < matB.col; c++){
				resultStruct.arr[r][c] =0;		
				for(int k = 0; k < matA.col; k++){
					resultStruct.arr[r][c] += matA.arr[r][k] * matB.arr[k][c];
				}
			}
		}		
	}else{
		resultStruct.row = 0;
		resultStruct.col = 0;
		printf("MatMult: The number of MatA-cols should be equal to MatB-rows\n");
	}
	resultStruct.row = matA.row;
	resultStruct.col = matB.col;	
	return resultStruct;	

}

 MATRIX matrixAddSub(char op, MATRIX matA, MATRIX matB){
	 MATRIX resultStruct;
	resultStruct.arr = malloc(matA.row*sizeof(*resultStruct.arr));
	for (int i=0; i < matA.row;i++){
		resultStruct.arr[i] = malloc(matA.col*sizeof(*resultStruct.arr));		
	}
	
	if((matA.row == matB.row) && (matB.col == matA.col)){
		for(int r = 0; r < matA.row; r++){
			for(int c = 0; c < matA.col; c++){
				resultStruct.arr[r][c] =('-' == op)	? matA.arr[r][c] - matB.arr[r][c] : matA.arr[r][c] + matB.arr[r][c];				
			}
		}		
	}else{
		resultStruct.row = 0;
		resultStruct.col = 0;
		printf("MatAddSub: Number of rows and cols of both Matrices should be equal\n");
	}
	
	resultStruct.row = matA.row;
	resultStruct.col = matB.col;	
	return resultStruct;
}