// c program to implement circular queues using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

struct node *insert(struct node *,int);
struct node *delete_element(struct node *);
struct node *display(struct node *);
int peek(struct node*);



void main()
{
	int val, option;
	do
	{
 		printf("\n\n *****MAIN MENU*****");
 		printf("\n 1. Insert an element ");
 		printf("\n 2. Delete an element");
 		printf("\n 3. Peek value");
 		printf("\n 4. Display the queue");
 		printf("\n 5. EXIT");
 		printf("\n Enter your option : ");
 		scanf("%d", &option);
		switch(option)
 		{
 			case 1:
 				printf("\n Enter the number to insert in the queue:");
 				scanf("%d", &val);
 				front = insert(front,val);
 				break;
 			case 2:
 				front = delete_element(front);
 				break;
 			case 3:
 				val = peek(front);
 				if(val != -1)
 					printf("\n The value at front of queue is : %d", val);
 					break;
			case 4:
				front = display(front);
 				break;
 		}
	}while(option != 5);
}

// this function is used to insert an element in to a queue
struct node *insert(struct node * front,int val)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	if( front == NULL && rear == NULL)
	{
 		front = ptr;
 		rear = ptr;
 		front -> next = rear -> next = ptr;
	}
	else
	{
 		rear -> next = ptr;
 		rear = ptr;
 		rear -> next = front;
	}
	return front;
}

//this function is used to delete an element an element from a queue.
struct node *delete_element(struct node *front)
{
	struct node *ptr;
	ptr = front;
	if(front == NULL)
 		printf("\n UNDERFLOW");
 	else if(front == rear)
 	{
 		front=rear=NULL;
 		printf("\n The value being deleted is : %d", ptr -> data);
 		free(ptr);
	 }
	else
	{
 		front = front -> next;
 		rear->next=front;
 		printf("\n The value being deleted is : %d", ptr -> data);
 		free(ptr);
	}
	return front;
}

//this function displays front value.
int peek(struct node *front)
{
	if(front==NULL)
	{
 		printf("\n QUEUE IS EMPTY");
 		return -1;
	}
	else
 		return front->data;
}


// this function is used to display the elements of queue
struct node *display(struct node *front)
{
	struct node *ptr;
	ptr = front;
	if(ptr == NULL)
 		printf("\n QUEUE IS EMPTY");
	else
	{
 		printf("\n");
 		while(ptr!=rear)
 		{
 			printf("%d\t", ptr -> data);
 			ptr = ptr -> next;
 		}
 		printf("%d\t", ptr -> data);
	}
	return front;
}
