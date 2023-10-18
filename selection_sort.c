#include<stdio.h>
#include<stdlib.h>

void selection_sort(int *a, int n);
void display(int *a, int n);
void swap(int *a, int *b);


int main()
{
	int n, *a;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	a=(int *)calloc(n,sizeof(int));
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("The sorted array in ascending order is\n");
	selection_sort(a, n);
	display(a, n);
	return 0;
}

void selection_sort(int *a, int n)
{
	int i, j, min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min])
				min=j;
		if(i!=min)
			swap(&a[i], &a[min]);
	}
}
void display(int *a, int n)
{
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
}
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
