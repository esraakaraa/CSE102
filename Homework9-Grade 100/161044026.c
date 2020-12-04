#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 25

struct person{
	char name[SIZE]; 
	char surname[SIZE]; 
	char musical_Work[SIZE]; 
	int age ;
	struct person *next; 
}*top;

void addNode(char name[], char surname [], char creation [], int age);
void deleteNode(struct person **top);
void print_stack();
void Sort_Increasingly();
void Sort_Alphabetically();


int main(){
	int menu;
	char name1[SIZE], surname1[SIZE] , creation1[SIZE];
	int age1;

	do{
		printf("\n***MENU*\n1- Add a Person to the Stack\n2- Pop a Person from the Stack\n3- Sort Alphabetical Order\n4- Sort Age in Increasing Order\n5- Exit menu\n*****");
		printf("\nPlease, Enter the number of menu.\n");
		scanf("%d" , &menu);
		switch (menu){
			case 1:
				printf("\nYour Choice : 1- Add a Person to the Stack\n");
				printf("Please,Enter the name , surname, musical work and age information respectively.\n");
				scanf(" %[^\n]s", name1 );
				scanf(" %[^\n]s", surname1 );
				scanf(" %[^\n]s", creation1 );
				scanf(" %d", &age1);
				addNode(name1 ,  surname1  , creation1 , age1);
				print_stack();
				break;
			case 2:
				deleteNode(&top);
				print_stack();
				break;
			case 3:
				Sort_Alphabetically();
				print_stack();
				break;
			case 4:
				Sort_Increasingly();
				print_stack();
				break;
			case 5:
				break;
			default:
				printf("Wrong choice.\n");
				break;
		}
	}
	while(menu != 5);

	return 0;
}

void print_stack(){
	int i = 1;
	struct person *temp;
	temp = top;
	if(temp ==  NULL){
		printf("Empty\n");
	}
	else{
		while(temp !=  NULL){
			printf("%d)Name : %s\nSurname : %s\nCreation : %s\nAge : %d\n", i , temp->name, temp->surname , temp->musical_Work , temp->age);
			temp = temp->next;
			i++;
		}
	}
}

void addNode(char name[SIZE], char surname[SIZE], char creation[SIZE], int age){
	if(top == NULL){
		top = (struct person*)malloc(sizeof(struct person));
		top->age = age;
		strcpy(top->surname , surname);
		strcpy(top->name , name);
		strcpy(top->musical_Work , creation);
		top->next = NULL;
	}
	else{
		struct person *head;
		head = (struct person*)malloc(sizeof(struct person));
		head->age = age;
		strcpy(head->surname , surname);
		strcpy(head->name , name);
		strcpy(head->musical_Work , creation);
		head->next = top;
		top = head;
	}
}

void deleteNode(struct person **head){
	if(*head == NULL){
		printf("Empty!\n");
	}
	else{
		*head = (*head)->next;
	}
}

void Sort_Increasingly(){
	struct person *temp, * swap;
	int data , i , count = 28;
	swap = (struct person*)malloc(sizeof(struct person));
	temp = top;
	for(i = 0 ; i < count ; i++){
		temp = top;
		count = 0;
		while(temp->next != NULL){
			if(temp->age > temp->next->age){
				swap->age = temp->age;
				strcpy(swap->surname , temp->surname);
				strcpy(swap->name , temp->name);
				strcpy(swap->musical_Work , temp->musical_Work);

				temp->age = temp->next->age;
				strcpy(temp->surname , temp->next->surname);
				strcpy(temp->name , temp->next->name);
				strcpy(temp->musical_Work , temp->next->musical_Work);


				temp->next->age = swap->age;
				strcpy(temp->next->surname , swap->surname);
				strcpy(temp->next->name , swap->name);
				strcpy(temp->next->musical_Work , swap->musical_Work);

			}
			temp = temp->next;
			count++;
		}
	}
}

void Sort_Alphabetically(){
struct person *temp, * swap ;
	int data , i , j, count = 28;
	swap = (struct person*)malloc(sizeof(struct person));
	temp = top;
	
	for(i = 0 ; i < count ; i++){
		temp = top;
		count = 0;
		while(temp->next != NULL){
			if(strcmp(temp->name, temp->next->name) > 0){
				swap->age = temp->age;
				strcpy(swap->surname , temp->surname);
				strcpy(swap->name , temp->name);
				strcpy(swap->musical_Work , temp->musical_Work);

				temp->age = temp->next->age;
				strcpy(temp->surname , temp->next->surname);
				strcpy(temp->name , temp->next->name);
				strcpy(temp->musical_Work , temp->next->musical_Work);


				temp->next->age = swap->age;
				strcpy(temp->next->surname , swap->surname);
				strcpy(temp->next->name , swap->name);
				strcpy(temp->next->musical_Work , swap->musical_Work);

			}
			temp = temp->next;
			count++;
		}
	}
}