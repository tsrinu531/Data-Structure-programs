#include<stdio.h>
void binary(int n, int arr[*],int beg, int end, int  val);
void main()
{
	int val,i,n;
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
	binary(n,arr,0,n-1,val);
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
