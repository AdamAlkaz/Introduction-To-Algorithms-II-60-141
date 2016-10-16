#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 20
#define ROW 20


/* SortMatrix: sorts a 2D array in decending order
* input: 2D int Array, the number of rows of the array, and the number of clumns of the array
 output: nothing is outputted but the contents of the array have been rearranged*/

void SortMatrix (int A[][COL], unsigned int rowsize, unsigned int colsize){
	int max = A[0][0];
	int count = 0;
	int Array [rowsize*colsize];
	for (int i = 0; i < rowsize; i++){
		for (int j = 0 ; j < colsize ; j++){
			Array [count] = A[i][j];
			count++;
		}
	}
	for (int i = 0; i < rowsize*colsize; i++){
		max = Array[i];
		for (int j = i ; j < rowsize*colsize ; j++){
			if (Array[j] > max){
				max = Array[j];
				Array[j] = Array[i];
				Array[i] = max;
			}
		}
	}
	count = 0;
	for (int i = 0; i < rowsize; i++){
		for (int j = 0 ; j < colsize ; j++){
			A[i][j] = Array [count];
			count++;
		}
	}
}

/* binsearch: takes a 1D matrix and splits it into sub arrays and looks for value vs
* input: 1D array, lower sub array, high sub array, value vs to search for
output: -1 if not found or the subscript of where the value is found */

int binsearch(int A[], int low, int high, int vs){

    int mid = (low+high)/2;
    if (A[mid] == vs) return mid;
    if( low > high) return -1;
    if(low <= high){

        if(vs  > A[mid]) {
                return binsearch(A, low, mid-1, vs);
        }else{
            return binsearch(A, mid+1, high, vs);
        }
    }
return 0;
}

/* SearchMatrix: searches a 2D matrix for a value and and returns the row and column
* input: a 2D array, an int V to search for, a pointer to the two integers for where the value of the row and column is,
* and the number of rows, and the number of columns
output: 1 if the number is in the array and -1 if its not found*/

int SearchMatrix(int A[ROW][COL], int V, int *P, unsigned int rowsize, unsigned int colsize ){
    int i = 0;
    int j;
    int B[colsize];
    while( i < (int)rowsize){
            for( j = 0; j < (int)colsize; j++){
                B[j] = A[i][j];
            }
            if(binsearch(B, 0, colsize, V) != -1 ) {
                    *P = i;
                    P++;
                    *P = binsearch(B, 0, colsize, V);
                    return 1;
            }
            i++;
    }
    return -1;

}

int main()
{
    int row, col;
    int P[2] = {-1,-1};
    int *pP = &P[0];
    int searchvalue;
    srand(time(NULL));


    printf("Enter the dimensions of the 2D array(e.g. 4 5): ");
    scanf("%d %d", &row, &col);

    int i, j;
    int A[ROW][COL];


    for( i = 0; i < row ; i++){
        for( j = 0; j < col; j++){
            A[i][j] = rand() % 100+1;
        }
    }


    SortMatrix (A, row, col);


    for(i = 0; i < row; i++){
        for( j = 0; j < col; j++){
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }





    printf("Enter the value you would like to search for: ");
    scanf("%d", &searchvalue);

    if(SearchMatrix(A, searchvalue, pP, row, col) == 1){
        printf("The value %d was found at row %d and coloumn %d.\n", searchvalue, P[0], P[1] );
    }else{
        printf("The value %d was not found.\n", searchvalue );
    }


}
