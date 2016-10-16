#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 20

void FillArray (int *array, int size){
	srand(time(NULL));
	int ran;
	for (int i = 0; i < size; i++){
		ran = rand() % 101;
		*(array + i) = ran;
	}
}

void PrintArray (int *array, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", *(array + i));
	}
	printf ("\n");
}

void Swap (int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort (int *array, int size){
	for (int i = 0; i < size ; i++){
		for (int j = 0 ; j < size - i; j++){
			if (*(array + j) < *(array + j + 1)){
				Swap (array + j, array + j + 1);
			}
		}
	}
}

void SelectionSort (int *array, int size){
	int addr = 0;
	int temp;
	for (int i = 0; i < size ; i++){
		for (int j = 0; j < size - i; j++){
			if (*(array + j) < *(array + addr)) addr = j;
		}
		temp = *(array + addr);
		*(array + addr) = *(array + (size - i));
		*(array + (size - i)) = temp;
		addr = 0;
	}
}

int main()
{
int a = 7 ; //value a is 7
int *aPtr ; //pointer variable
aPtr = &a ; // points to address of a
printf( "%p\n", &a ); //prints address of a
printf( "%p\n", aPtr ); //prints address of a
printf( "%p\n", &aPtr ); //prints address of pointer to a
printf( "%d\n", a ); //prints value 7
printf( "%d\n", *aPtr ); //prints value 7
printf( "%p\n", *&aPtr ); //prints value of pointer (address of a)
printf( "%p\n", &*aPtr ); //prints address of a
printf( "%d\n", *&a ); //prints 7
//printf( "%d", &*a ); //error can't deallocate value

int array[SIZE];
int *arrPtr = array;
FillArray(arrPtr, SIZE);
BubbleSort (arrPtr, SIZE);
PrintArray (arrPtr, SIZE);

int array2[SIZE];
int*arrPtr2 = array2;
FillArray(arrPtr2, SIZE);
SelectionSort (arrPtr2, SIZE);
PrintArray (arrPtr2, SIZE);
return 0;
}
