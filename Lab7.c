#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	float hourlywage;
};
typedef struct employee Employee;

void InputEmpRecord (Employee *EmpList){
	for (int i = 0; i<3; i++, EmpList++){
		char line[100];
		printf("Enter the employee information seperated by ','\n");
		fgets(line, 100, stdin);

		char idTok[6];
		strcpy (idTok, strtok(line,",\n"));
		EmpList -> id = (idTok[0] - '0') * 10 + (idTok[1] - '0');

		strcpy(EmpList -> firstname, strtok (NULL, ",\n"));
		strcpy (EmpList -> lastname, strtok(NULL,",\n"));

		char salTok[6];
		strcpy (salTok, strtok(NULL, ",\n"));
		EmpList -> hourlywage = (salTok[0] - '0') * 10 + (salTok[1] - '0') + (salTok[3] - '0') * 0.1 + (salTok[4] - '0')*0.01;
	}

}

char *PrintEmpList (Employee *EmpList, char *String){
	char empl[100];
	sprintf(empl, "%d %s %s %.2f\n",EmpList -> id, EmpList -> firstname, EmpList -> lastname, EmpList -> hourlywage);
	strcpy(String, empl);
	return String;
}

void SaveEmpList (Employee *EmpList, char *FileName){
	char String[300];
	FILE *fpointer;
	fpointer = fopen(FileName, "w");
	PrintEmpList(EmpList,String);
	EmpList++;
	fprintf(fpointer,String);
	PrintEmpList(EmpList,String);
	EmpList++;
	fprintf(fpointer,String);
	PrintEmpList(EmpList,String);
	fprintf(fpointer,String);
	fclose(fpointer);
}

void CapWord (char *word){
	*word = *word - 32;
}

void CapEmpList (Employee *EmpList){
	FILE *fpointer;
	char line [300], *token;
	fopen ("employee.txt","r");
	while(!feof(fpointer)){
		fgets(line, 300, fpointer);
		token = strtok(line," ");
		token = strtok(NULL," ");
		CapWord(token);
		strcpy(EmpList -> firstname, token);
		token = strtok(NULL," ");
		CapWord(token);
		strcpy(EmpList -> lastname, token);
		EmpList++;
	}
	fclose(fpointer);
}

int main (void){
	Employee emp[2];
	Employee *empPtr = emp;
	//InputEmpRecord (empPtr);
	//empPtr = emp;
	//SaveEmpList (empPtr, "employee.txt");
	//empPtr = emp;
	CapEmpList(empPtr);
	empPtr = emp;
	SaveEmpList (empPtr, "employee.txt");

}
