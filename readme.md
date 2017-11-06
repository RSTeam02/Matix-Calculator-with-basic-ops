# Matrix Calculator with basic operations (+,-,*)

+ update: preview values from a00 to aRC, input validation => check if integer and right operation entered 
+ basic operation of 2x matrices (MatResult = MatA operation MatB)
+ struct definition for creating a Matrix type, eg. MATRIX matA 
+ enter number of rows/columns, values of a matrix (a00, a01...aRC)
+ catch error when number of row, col of matA, matB aren't equivalent

usage:

```
$ gcc main.c matrix.c -std=c99 -o main
$ ./main
Enter number of rows of MatA: 2
Enter number of columns of MatA: 3
( a00 a01 a02 )
( a10 a11 a12 )

Enter Matrix values:
a00: 4
a01: 6
a02: 3
a10: 1
a11: 8
a12: 9
(     4    6    3   )
(     1    8    9   )

Enter number of rows of MatB: 3
Enter number of columns of MatB: 2
( a00 a01 )
( a10 a11 )
( a20 a21 )

Enter Matrix values:
a00: 8
a01: 9
a10: 0
a11: 5
a20: 3
a21: 4
(     8    9   )
(     0    5   )
(     3    4   )

Select operation +,- or *: *
Result:
(    41   78   )
(    35   85   )
```