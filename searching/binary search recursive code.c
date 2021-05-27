#include<stdio.h>
int binarysearch(int n, int arr[*],int beg, int end, int val);
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
	pos=binarysearch(n,arr,0,n-1,val)+1;
	if(pos!=0)
		printf("\n element %d is found at %dth position",val,pos);
	else
		printf("\n %d not found in the array",val);
}
int binarysearch(int n, int arr[n],int beg, int end,int val)
{
	if(beg<=end)
	{
		int mid=(beg+end)/2;
		if(arr[mid]==val)
			return mid;
		if(arr[mid]>val)
			return binarysearch(n,arr,beg,mid-1,val);
		else
			return binarysearch(n,arr,mid+1,end,val);
	}
	return -1;
}
