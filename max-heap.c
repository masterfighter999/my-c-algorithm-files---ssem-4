#include <stdio.h>

void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
  
    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;
  
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;
  
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
  
        max_heapify(arr, n, largest);
    }
}

void build_max_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}

void display_max_heap(int arr[], int n) {
    printf("Max Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
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
  
    build_max_heap(arr, N);
    display_max_heap(arr, N);

    return 0;
}
