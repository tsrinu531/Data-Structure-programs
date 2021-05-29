/* a) Write C program that implement Bubble sort, to sort a given list of integers in ascending 
order */
#include<stdio.h>
void main()
{
	int n,temp,i,j,arr[50];
	printf("enter the size of an array");
	scanf("%d",&n);
	printf("enter the %d elements: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	// bubble sort logic
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++) 
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	printf("\n After sorting the elements of an array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
