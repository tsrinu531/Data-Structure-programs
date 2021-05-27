#include<stdio.h>
int linear_search_re(int val, int n, int arr[*]);
void main()
{
	int val,i, n, pos;
	printf("enter the size of an array");
	scanf("%d",&n);
	int arr[n];
	printf("\n enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the value to search:");
	scanf("%d",&val);
	pos=linear_search_re(val,n,arr);
	if(pos!=0)
		printf("element %d is found at %dth position",val,pos);
	else
		printf("\n %d is not found in the array",val);
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
