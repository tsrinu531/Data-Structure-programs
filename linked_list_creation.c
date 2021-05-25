#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct noden* next;
};
struct node* start = NULL;
struct node* createll(struct node *);
void display(struct node *);
void main()
{
	int option;
	do
	{
		printf("\n enter 1, to create a list.");
		printf("\nenter 2, to display a list.");
		printf("\nenter 3, to exit.");
		printf("\nenter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				start = createll(start);
				printf("\n linked list is created");
				break;
			case 2:
				display (start);
				break;
		}
	}while(option != 3);
}
struct node* createll(struct node* start)
{
	struct node* newnode, * ptr;
	int num;
	printf("\n enter the data or -1 to end");
	scanf("%d",&num);
	while(num!= -1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		if(start == NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr = start;
			while(ptr->next != NULL)
				ptr = ptr -> next;
			ptr->next=newnode;
			newnode->next=NULL;
	    }
	    printf("\n enter the data: ");
	    scanf("%d",&num); 
	   }
	   return start;
	}
	void display(struct node* start)
	{
		struct node * ptr;
		ptr=start;
		while (ptr != NULL)
		{
			printf("%d\t ", ptr->data);
			ptr=ptr->next;
		}
	}
