/* C program to insert a node at beginning and end of a circular linked list */ 
#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *start = NULL;
struct node *create_cll(struct node *);
void *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
void main()
{
 	int option;
 	do
 	{
		printf("\n\n *****MAIN MENU *****");
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Add a node at the beginning");
		printf("\n 4: Add a node at the end");	
		printf("\n 5: EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
 			case 1: start = create_cll(start);
 					printf("\n CIRCULAR LINKED LIST CREATED");
 					break;
 			case 2: display(start);
 					break;
 			case 3: start = insert_beg(start);
 					break;
 			case 4: start = insert_end(start);
 					break;
		}
 	}while(option !=5);
}

struct node *create_cll(struct node *start)
{
	struct node *new_node, *ptr;
 	int num,n,i;
 	printf("enter the number of nodes to store in the linked list: ");
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	{
 		printf("enter the data in the %d node: ",i);
 		scanf("%d",&num);
 		new_node = (struct node*)malloc(sizeof(struct node));
 		new_node -> data = num;
 		if(start == NULL)
 		{
 			start = new_node;
 			new_node -> next = new_node;
  		}
 		else
 		{ 
		 	ptr = start;
 			while(ptr -> next != start)
 				ptr = ptr -> next;
 			new_node -> next = start;
 			ptr -> next = new_node;
 		}
	}
	return start;
}
void *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr -> next != start)
	{
 		printf("\t %d", ptr -> data);
 		ptr = ptr -> next;
	}
	printf("\t %d", ptr -> data);
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
 		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = start;
	start = new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
 		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = start;
	return start;
}
