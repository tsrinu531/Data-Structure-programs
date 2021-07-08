// C program to implement Breadth first search
#include<stdio.h>
#include<stdlib.h>
 
#define MAX 20  
 
#define initial 1
#define waiting 2
#define visited 3
 
   
int graph[MAX][MAX];
int n; 
int status[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);
 
int queue[MAX], front = -1,rear = -1;
void enqueue(int vertex);
int dequeue();
int isempty();
 
void main()
{
	create_graph();
	BF_Traversal();
}
 
void BF_Traversal()
{
	int v;
	for(v=1; v<=n; v++)
		status[v] = initial;
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	BFS(v);
}
 
void BFS(int v)
{
	int i;
	enqueue(v);
	status[v] = waiting;
	while(!isempty())
	{
		v = dequeue( );
		printf("%d ",v);
		status[v] = visited;
		for(i=1; i<=n; i++)
		{
			if(graph[v][i] == 1 && status[i] == initial)
			{
				enqueue(i);
				status[i] = waiting;
			}
		}
	}
	printf("\n");
}
 
void enqueue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}
 
int isempty()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
int dequeue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
 
void create_graph()
{
	int i,max_edge,row,column;
 	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edge = n*(n-1);
 	for(i=1; i<=max_edge; i++)
	{
		printf("Enter edge %d( 0 0 to quit ) : ",i);
		scanf("%d %d",&row,&column);
 		if((row == -1) && (column == -1))
			break;
		if(row>n || column>n || row<=0 || column<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			graph[row][column] = 1;
	}
}
