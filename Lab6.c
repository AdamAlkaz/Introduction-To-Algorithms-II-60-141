#include <stdio.h>
#include <string.h>

void Swap (char *x, char *y){
	char temp = *y;
	*y = *x;
	*x = temp;
}

void Reverse (char *stringArr){
	int size = strlen(stringArr);
	int mid;
	if (size%2 == 0) mid = size / 2 - 1;
	else mid = size/2;
	for (int i = 0 ; i < mid ; i++){
		Swap (stringArr + i, stringArr + size - 1- i);
	}
}

void ParseSentence (char stringArr[]){
	char *delim = strtok(stringArr," ,\n");;
	while (delim != NULL){
		printf("%s\n", delim);
		delim = strtok(NULL," ,\n");;
	}
}

int main (void){
	char buffer1 [] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','\0'};
	char buffer2 [] = "this is the second buffer";
	printf ("%s\n%s\n", buffer1,buffer2);
	char buffer3 [80];
	char temp = getchar();
	char *b3Ptr = buffer3;
	while (temp != '\n'){
		*b3Ptr = temp;
		b3Ptr++;
		temp = getchar();
	}
	b3Ptr = buffer3;
	while (*b3Ptr != '\0'){
		printf ("%c", *(b3Ptr++));
	}
	printf ("\n");
	b3Ptr = buffer3;
	Reverse (b3Ptr);
	printf("%s\n", buffer3);
	char buffer4 [] = "hello world, how are you today";
	ParseSentence (buffer4);
}
