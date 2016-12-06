#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct mystr { 
	struct mystr *next, *prev; 
	int age; 
	char *name; 
}; 
struct mystr *head = 0; 

void addNode(char *name, int age); 
void changeName(char *name, int age); 
int countNodes(int age); 
void print();
void removeAll(); 

int main()
{
	addNode("kim", 20); 
	addNode("park", 21); 
	addNode("choi", 22); 
	print(); 

	changeName("lee", 21);
	print(); 

	addNode("sun" , 22);
	printf("the nunber of node = %d\n", countNodes(22));
	print(); 

	removeAll();
	print(); 

	return 0; 
} 

void addNode(char *name, int age)
{
	struct mystr *new, *tmp; 

	if( (new = malloc(sizeof(struct mystr))) == NULL ) 
	{
		fprintf(stderr , "동적할당 오류\n"); 
		exit(1); 
	} 
	new -> name = malloc(128); 

	strcpy( new -> name, name ); 
	new -> age = age; 
	new -> next = NULL; 
	new -> prev = NULL; 

	if(head == NULL) 
	{
		head = new;
		return ;
	} 

	tmp = head; 
	head = new; 
	head -> next = tmp; 
	tmp -> prev = head; 
}

void print()
{
	struct mystr *tmp; 

	for( tmp = head; tmp; tmp -> next)
	{
		printf("%s, %d\n" , tmp -> name, tmp -> age); 
		tmp = tmp -> next; 
	}

	printf("\n\n");
}

void changeName(char *name, int age)
{	
	struct mystr *tmp; 

	for(tmp = head; tmp; tmp = tmp -> next) 
	{
		if(tmp -> age == age) 
		{
			strcpy(tmp -> name, name);
			return ;
		}
	}
	 
	tmp = head;
	strcpy(tmp -> name, name); 	
}

int countNodes(int age) 
{ 
	struct mystr *tmp;
	int count = 0; 

	for(tmp = head; tmp; tmp = tmp -> next) 
		if(tmp -> age == age) 
			 count++; 
	
	return count; 
}

void removeAll()
{
	struct mystr *tmp; 

	for(tmp = head; tmp; tmp = tmp -> next) 

	while(!tmp)
	{
		free(tmp -> name);
		free(tmp);
		tmp = tmp -> prev; 
	}
}
		
