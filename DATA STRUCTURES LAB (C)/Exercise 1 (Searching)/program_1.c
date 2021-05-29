/* a)Write C program that use both recursive and non recursive functions to perform Linear 
search for a Key value in a given list. */

#include<stdio.h>
void linear_search(int val,int n,int arr[*]);
int linear_search_re(int val, int n, int arr[*]);
void main()
{
	int val,i,n,pos;
	printf("enter the size of an array: ");
	scanf("%d",&n);
	int arr[n];
	printf("\n enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n enter the value to search: ");
	scanf("%d",&val);
	printf("\n\n searching of an element using non-recursive funcion");
	printf("\n -------------------------------------------------------");
	linear_search(val,n,arr);
	printf("\n\n searching of an element using recursive funcion");
	printf("\n -------------------------------------------------------");
	pos=linear_search_re(val,n,arr);
	if(pos!=0)
		printf("\n element %d is found at %d position",val,pos);
	else
		printf("\n %d is not found in the array",val);
}
void linear_search(int val, int n, int arr[n])
{
	int i,pos=-1;
	for(i=0;i<n;i++)
	{
		if(arr[i]==val)
		{
			pos = i;
			printf("\n %d is found in the array at position %d",val,i+1);
			
		}
	}
	if(pos==-1)
		printf("\n %d does not found in the array ",val);			
}
int linear_search_re(int val, int n, int arr[n])
{
	if(n>=0)
	{
		if(arr[n-1]==val)
			return n;
		else
			return linear_search_re(val,n-1,arr);
	}
}
