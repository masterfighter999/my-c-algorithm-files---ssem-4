// Heap Sort in C

#include <stdio.h>
#include<stdlib.h>

void swap(int* a, int* b);
void heapify(int arr[], int N, int i);
void heapSort(int arr[], int N);
void printArray(int arr[], int N);


int main()
{
	int n;
	printf("Enter the size of the array\n");
	scanf("%d", &n );
	//int *arr;
	//arr = (int *)calloc(n,sizeof(int)); 
	int arr[n];
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	int N = sizeof(arr) / sizeof(arr[0]);

	
	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);
}


void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}

void heapify(int arr[], int N, int i)
{
	
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < N && arr[left] > arr[i])

		largest = left;

	
	if (right < N && arr[right] > arr[largest])

		largest = right;

	
	if (largest != i) {

		swap(&arr[i], &arr[largest]);
		heapify(arr, N, largest);
	}
}

void heapSort(int arr[], int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);

	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}




