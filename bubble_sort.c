#include<stdio.h>
#include<stdlib.h>

void display(int *a, int n);
void swap(int *a, int *b);
void bubble_sort(int *a,int n);

int main()
{
	int n, *a;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	a=(int *)calloc(1,sizeof(int));
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("The sorted array in ascending order is\n");
	bubble_sort(a, n);
	display(a, n);
	return 0;
}
void bubble_sort(int *a, int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(a[j+1]<a[j])
				swap(&a[j+1], &a[j]);
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

