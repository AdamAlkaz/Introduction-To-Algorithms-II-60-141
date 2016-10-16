#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 6
#define N 5

void populate2DArray (int A[][N]){
	srand(time(NULL));
	for (int i = 0; i < M ; i++){
		for (int j = 0; j < N ; j++)
			A[i][j] = rand()%(M*N) + 1;
	}
}

void print2DArray(int A[][N]){
	for (int i = 0 ; i < M ; i++){
		for (int j = 0 ; j < N; j++)
			printf("%4d", A[i][j]);
		printf("\n");
	}
}

bool LinearSearch2D (int A[][N], int x){
	for (int i = 0 ; i < M ; i++){
		for (int j = 0 ; j < N; j++){
			if (A[i][j] == x)
				return true;
		}
	}
	return false;
}

void LeftShift2D (int A[][N]){
	int storeInt = A[M-1][N-1];
	A[M-1][N-1] = A[0][0];
	int row = M - 1;
	int col = N - 2;
	int next;
	while(1){
		next = A[row][col];
		A[row][col] = storeInt;
		storeInt = next;
		col -= 1;
		if (col < 0){
			row -= 1 ;
			col = N -1;
		}
		if (row < 0)
			break;
	}
}


int main (void){
	int Array[M][N] = {0};
	populate2DArray(Array);
	print2DArray(Array);
	printf("\nIs 5 in the array?  %s\n",LinearSearch2D(Array, 5)?"True":"False");
	printf("\n");
	LeftShift2D(Array);
	print2DArray(Array);
	printf("\n");
	LeftShift2D(Array);
	print2DArray(Array);
}
