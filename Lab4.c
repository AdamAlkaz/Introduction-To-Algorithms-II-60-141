#include <stdio.h>

int *Largest (int *array, int size){
	int largestVal = *array;
	int *address = array;
	for (int i = 0 ; i < size; i++){
		if (largestVal < *(array+i)){
			largestVal = *(array+i);
			address = array+i;
		}
	}
	return address;
}

void swap (int *x, int *y){
	int storePtr = *y;
	*y = *x;
	*x = storePtr;
}

int main(){
	int array[] = {5,3,6,7,11,6,34,41,23,10};
	int *aPtr = array;
	printf ("Largest is %d\n", *Largest(aPtr,10));

	int x = 2;
	int y = 6;
	swap (&x, &y);
	printf("value of x: %d, value of y: %d", x,y);
}
