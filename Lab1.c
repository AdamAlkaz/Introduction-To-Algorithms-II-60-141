#include <stdio.h>

int sum (int n){
	int sumNum = 0;
	if (n == 0) return sumNum;
	else sumNum += n + sum(n-1);
}

void fib (int n){
	long fibArray[n];
	for (int i = 0 ; i < n; i++){
		if (i == 0)
			fibArray[i] = 0;
		else if (i == 1)
			fibArray[i] = 1;
		else fibArray [i] = fibArray[i-1] + fibArray [i-2];
	}
	for (int i = 0 ; i < n ; i ++)
		printf ("%ld  ", fibArray[i]);
}

int gcd (int a, int b){
	int big;
	if (a>b)
		big = a;
	else
		big = b;
	for (int i = big ; i > 0 ; i--){
		if (a%i == b%i ==0)
			return i
	}
}

int main (void){
	int a,b;
	printf ("Enter an integer: ");
	scanf ("%d", &a);
	printf ("sum(%d) = %d\n",a,sum(a));
	printf("Enter number of iterations of Fibonacci sequence");
	scanf ("%d", &a);
	fib (a);
	printf("Enter two numbers
}
