# Matrix Calculator with basic operations (+,-,*)

+ 7.11: input validation without goto, repeat only last input (arrays)
+ update: print preview from a00 to aRC, input validation => check if integer and right operation entered 
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
a00: 5
a01: 8
a02: 53
a10: 5
a11: 0
a12: 9
(     5    8   53   )
(     5    0    9   )

Enter number of rows of MatA: 3
Enter number of columns of MatA: 
h
not an integer, repeat input columns
2
( a00 a01 )
( a10 a11 )
( a20 a21 )

Enter Matrix values:
a00: 6
a01: 3
a10: 8
a11: v
not an integer, repeat input
a11: 3
a20: 7
a21: 9
(     6    3   )
(     8    3   )
(     7    9   )

Select operation +,- or *: ,
invalid operation
Select operation +,- or *: *
Result:
(   465  516   )
(    93   96   )
```