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
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);

void main()
{
	int option;
	do
	{
		printf("\n\n ***** MAIN MENU *****");
		printf("\n 1: cearte a list");
		printf("\n 2: Display a list");
		printf("\n 3: Delete a node from the beginning");
 		printf("\n 4: Delete a node from the end");
		printf("\n 5: Delete a node after a given node");
		printf("\n 6: Exit");
		printf("\n\n Enter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: start= create_dll(start);
					printf("\n Doubly linked list created.");
					break;
			case 2: display(start);
					break;
			case 3: start = delete_beg(start);
 					break;
 			case 4: start = delete_end(start);
 					break;
 			case 5: start = delete_after(start);
 					break;
		}
	}while(option != 6);
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

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start = start -> next;
	start -> prev = NULL;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr -> next != NULL)
 		ptr = ptr -> next;
	ptr -> prev -> next = NULL;
	free(ptr);
	return start;
}

struct node *delete_after(struct node *start)
{
	struct node *ptr, *temp;
	int val;
	printf("\n Enter the value after which the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
	while(ptr -> data != val)
 		ptr = ptr -> next;
	temp = ptr -> next;
	ptr -> next = temp -> next;
	temp -> next -> prev = ptr;
	free(temp);
	return start;
}
