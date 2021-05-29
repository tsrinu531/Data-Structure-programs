/* b) Write C program that use both recursive and non recursive functions to perform Binary 
search for a Key value in a given list. */

#include<stdio.h>
void binary(int n, int arr[*],int beg, int end, int  val);
int binary_re(int n, int arr[*],int beg, int end, int val);
void main()
{
	int val,i,n,pos;
	printf("enter the size of an array: ");
	scanf("%d",&n);
	int arr[n];
	printf("\n enter the elements in ascending order: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n enter the value to search: ");
	scanf("%d",&val);
	printf("\n\n searching of an element using non-recursive funcion");
	printf("\n -------------------------------------------------------");
	binary(n,arr,0,n-1,val);
	printf("\n\n searching of an element using recursive funcion");
	printf("\n -------------------------------------------------------");
	pos=binary_re(n,arr,0,n-1,val);
	if(pos!=-1)
		printf("\n element %d is found at %dth position",val,pos+1);
	else
		printf("\n %d not found in the array",val);
}
void binary(int n,int arr[n],int beg, int end,int val)
{
	int mid, pos=-1;
	while(beg<=end)
	{
		mid = (beg+end)/2;
		if(arr[mid]==val)
		{
			pos=mid+1;
			printf("\n element %d is found at %dth position",val,pos);
			break;
		}
		else if(arr[mid]>val)
			end=mid-1;
		else 
			beg=mid+1;
	}
	if(pos==-1)
		printf("\n %d does not found in the array",val);		
}
int binary_re(int n, int arr[n],int beg, int end,int val)
{
	if(beg<=end)
	{
		int mid=(beg+end)/2;
		if(arr[mid]==val)
			return mid;
		if(arr[mid]>val)
			return binary_re(n,arr,beg,mid-1,val);
		else
			return binary_re(n,arr,mid+1,end,val);
	}
	return -1;
}
