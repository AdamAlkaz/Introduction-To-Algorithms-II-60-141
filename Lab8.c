#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int ID;
	char name[40];
	struct student *next;
};
typedef struct student Student;

int getChoice();
Student *addToList(Student *List);
void printList(Student *List);
//void printListRR(Student *List);
//void searchList(Student *List);

int main() {
	int choice = 0;
	Student *SLIST = NULL;
	choice = getChoice();
	while(choice != 0) {
		switch(choice) {
			case 0 : printf("Bye...\n"); exit(0);
			case 1 : SLIST = addToList(SLIST); break;
			case 2 : printList(SLIST); break;
			//case 3 : printListRR(SLIST); break;
			//case 4 : searchList(SLIST); break;
			default: printf("That is not a valid choice\n");
		}
	choice = getChoice();
	}
	if(SLIST) free(SLIST);
		return 0;
}

int getChoice() {
	int choice = 0;
	printf("\n****** MENU ******\n");
	printf("1. Add new student to list.\n");
	printf("2. Print the student list, beginning to end.\n");
	printf("3. Recursively print the student list from the end.\n");
	printf("4. Search the list for a student.\n");
	printf("0. Quit.\n");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	return choice;
}

Student *addToList(Student *List){
	int id = 0;
	char name[40], line[100],*token;
	puts("enter student id then name");
	gets (line);
	token = strtok (line," \n");
	for (int i = 0; i < strlen(token); i++){
		id = id*10 + (token[i] - '0');
	}
	strcpy(name,strtok(NULL," \n"));
	Student *stdPtr, *temp;
	temp = (Student*)malloc(sizeof(Student));
	if (List == NULL){
		List -> ID = id;
		strcpy(List -> name, name);
		List = temp;
		List -> next = NULL;
	}
	else{
		stdPtr = List -> next;
		while(stdPtr != temp){
			if (stdPtr -> next == NULL){
				stdPtr -> next = temp;
			}
			stdPtr = stdPtr -> next;
		}
		stdPtr -> ID = id;
		strcpy(stdPtr -> name,name);
		stdPtr -> next = NULL;
	}
	return List;
}

void printList(Student *List){
	while(List != NULL){
		printf("student id: %d, name: %s\n", List -> ID, List -> name);
		List = List -> next;
	}
}
