/**
 * @sakaijun
 * C-Version
 *
 * calculate 2 Matrices +,-,*
 * declare 2 dim arrays and create structs
 * init empty pointer array => copy arrays with x,y length information into structs
 * use Matrix struct for calculation  
 * integer validation check: https://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c
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
    
    RCA: 
    for(int i =0; i < sizeof(rcA)/sizeof(rcA[0]); i++){
        printf("Enter number of %s of MatA: ", rcInfo[i]);        
        if (scanf("%d", &rcA[i]) != 1){ //every integer input has a length of 1, a char input 2, including \n termination
            printf("not an integer, repeat input row/col\n");
            while(getchar() != '\n'); //clear scanf input
            goto RCA; //repeat and goto label on top                
        }        
    }    
    
    int matA[rcA[0]][rcA[1]];

    printf("Enter Matrix values:\n");
    MATA_INPUT:
    for(int i =0; i < rcA[0]; i++){
        for(int j =0; j < rcA[1]; j++){
            printf("a%d%d: ", i,j);			
            if (scanf("%d", &matA[i][j]) != 1){
                printf("not an integer, repeat input values\n");
                while(getchar() != '\n');
                goto MATA_INPUT;                
            }           			
        }
    }

    matAStruct = generateMat(rcA[0], rcA[1], matA);
    printRes(matAStruct);

    RCB: 
    for(int i =0; i < sizeof(rcB)/sizeof(rcB[0]); i++){
        printf("Enter number of %s of MatB: ", rcInfo[i]);        
        if (scanf("%d", &rcB[i]) != 1){
            printf("not an integer, repeat input row/col\n");
            while(getchar() != '\n');
            goto RCB;                
        }        
    }    
    
    int matB[rcB[0]][rcB[1]];

    printf("Enter Matrix values:\n");
    MATB_INPUT:
    for(int i =0; i < rcB[0]; i++){
        for(int j =0; j < rcB[1]; j++){
            printf("a%d%d: ", i,j);
            int input = scanf("%d", &matB[i][j]);       
            if (input != 1){
                
                printf("not an integer, repeat input values\n");
                while(getchar() != '\n');
                goto MATB_INPUT;                
            }      			
        }
    }

    matBStruct = generateMat(rcB[0], rcB[1], matB);	
    printRes(matBStruct);

    OP: do{
        printf("Select operation +,- or *: ");	
        scanf("\n%c", &op);
        if(op == '+' || op == '-' || op == '*'){
            if(op == '+'){
                matResStruct = matrixAddSub('+',matAStruct, matBStruct);
            }else if(op == '-'){
                matResStruct = matrixAddSub('-',matAStruct, matBStruct);
            }else{
                matResStruct = matrixMult(matAStruct,matBStruct);
            }
            printf("Result:\n");
            printRes(matResStruct);
            break; //if input succeeded leave loop
        }else{
            printf("invalid operation\n");
            goto OP; //repeat, if input is not +,-, or *
        }
    }while(1);
     
}
