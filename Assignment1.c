#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 20
#define ROW 20

//this function populates a 2D array of random integeres between a specified range
void populateArray2DUnique (int A[][COL], unsigned int rowSize, unsigned int colSize, int min, int max)
{
	srand(time(NULL));

	//generating a random value for eveyspot in the 2D array
	for (int i = 0; i < rowSize ; i++ ){
		for (int j = 0 ; j < colSize ; j++ )
			A[i][j] = rand()%(max + 1 - min) + min;  //random value from 0 to the range of max - min plus the minimum
	}							//this yield a range from min to max including both min and max
}

//this function prints out the entire array
void displayArray (int A[][COL], unsigned int rowSize, unsigned int colSize)
{
	for (int i = 0; i < rowSize; i++){
		for (int j = 0; j < colSize; j++)
			printf("%d ",A[i][j]);      //print stored integer
		printf("\n");
	}
}

//Function to find largest value in the array
int findLargest (int A[][COL], unsigned int rowSize, unsigned int colSize)
{
	int largest = A[0][0];  //initializing largest variable to first element of array
	for (int i = 0; i < rowSize ; i++ ){
		for (int j = 0 ; j < colSize ; j++ ){
			if (A[i][j] > largest)
				largest = A[i][j]; 	//comparing every element to the stored largest value and returning to user
		}
	}
	return largest;
}

//function to make a transpose of the original array
void Transpose (int A[][COL],int B[][ROW], unsigned int rowSize, unsigned int colSize){
	for (int i = 0; i < rowSize; i++){
		for (int j = 0; j < colSize; j++)
			B[j][i] = A[i][j];        //switching rows and columns
	}
}

int main (void)
{
	unsigned int rSize, cSize;	//row and column sizes
	int min,max;
	int Array[ROW][COL] = {0};	//initialize array
	int BArray[COL][ROW]= {0};
	printf("Enter row size, and column size respectively\n(row and column size must be less than 20)\n");
	scanf(" %u %u",&rSize, &cSize);
	printf("Enter the minimum and maximum values\n");
	scanf("%d%d",&min,&max);
	printf("\nDisplay Array 2D:\n");
	populateArray2DUnique (Array, rSize, cSize, min, max);
	displayArray(Array, rSize, cSize);
	printf("\nLargest: %d\n\n",findLargest(Array,rSize,cSize));
	printf("Transpose of A to B:\n");
	Transpose (Array,BArray,rSize,cSize);
	displayArray(BArray, cSize, rSize);
}
