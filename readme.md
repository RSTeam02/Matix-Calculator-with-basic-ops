# Matrix Calculator with basic operations (+,-,*)

+ basic operation of 2x matrices (MatResult = MatA operation MatB)
+ struct definition for creating a Matrix type, eg. MATRIX matA 
+ enter number of rows/columns, values of a matrix (a00, a01...aRC)
+ catch error when number of row, col of matA, matB aren't equivalent

usage:

```
$ gcc main.c matrix.c -std=c99 -o main
$ ./main
Enter number of rows of MatA: 3
Enter number of columns of MatA: 3
Enter Matrix values:
a00: 23
a01: 45
a02: 32
a10: 11
a11: 33
a12: 44
a20: 55
a21: 3
a22: 21
(    23   45   32   )
(    11   33   44   )
(    55    3   21   )

Enter number of rows of MatB: 3
Enter number of columns of MatB: 3
Enter Matrix values:
a00: 32
a01: 12
a02: 45
a10: 32
a11: 45
a12: 66
a20: 43
a21: 22
a22: 3
(    32   12   45   )
(    32   45   66   )
(    43   22    3   )

Select operation +,- or *:
-
(    -9   33  -13   )
(   -21  -12  -22   )
(    12  -19   18   )
```