#include <stdio.h>

int max (int a, int b){
	if (a>b)
		return a;
	else
		return b;
}

int max3 (int a, int b, int c){
	if (a > b && a > c)
		return a;
	else if (b > a && b > c)
		return b;
	else
		return c;
}

int sum (int n){
	int sumNum = 0;
	for (int i = 0; i <= n ; i++)
		sumNum += i;
	return sumNum;
}

void DrawSquare (int L, char s){
	for (int i = 0 ; i <= L ; i++){
		for (int j = 0 ; j <= L; j++)
			printf ("%c\t", s);
		printf ("\n");
	}
}

int main (void){
	int a, b, c;
	char ch;
	printf ("Please enter two integers: ");
	scanf ("%d%d", &a, &b);
	printf("max(%d, %d) has returned %d\n\n", a, b, max (a, b));
	printf ("Please enter three integers: ");
	scanf ("%d%d%d", &a, &b, &c);
	printf ("max3(%d,%d,%d) has returned %d\n\n", a, b, c, max3(a,b,c));
	printf ("Enter a positive integer n: ");
	scanf ("%d",&a);
	printf ("sum(%d) = %d\n\n", a, sum(a));
	printf ("Enter value of L: ");
	scanf ("%d",&a);
	printf("Enter character s: ");
	ch = getchar();
	ch = getchar();
	printf("\n");
	DrawSquare (a,ch);
}
