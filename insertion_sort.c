#include<stdio.h>
#include<stdlib.h>

void display(int *a, int n);
void swap(int *a, int *b);
void insertionSort(int *a, int n);

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
    insertionSort(a, n);
	display(a, n);
	return 0;
}

void insertionSort(int *a, int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = a[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void display(int *a, int n)
{
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
}

