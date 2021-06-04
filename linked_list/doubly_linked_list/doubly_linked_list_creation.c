#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* prev;
	int data;
	struct node* next;
};
struct node *start=NULL;
struct node* create_dll(struct node*);
void display(struct node*);

void main()
{
	int option;
	do
	{
		printf("\n\n ***** MAIN MENU *****");
		printf("\n 1: cearte a list");
		printf("\n 2: Display a list");
		printf("\n 3: Exit");
		printf("\n\n Enter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: start= create_dll(start);
					printf("\n Doubly linked list created.");
					break;
			case 2: display(start);
					break;
		}
	}while(option != 3);
}

struct node* create_dll(struct node* start)
{
	struct node* new_node, *ptr;
	int num,n,i;
	printf("\n enter the number of nodes to store in a list: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n enter the data in the %d node: ",i);
		scanf("%d",&num);
		new_node= (struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			new_node->prev=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next != NULL)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
			new_node->prev=ptr;
		}
	}
	return start;
}

void display(struct node* start)
{
	struct node* ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}
