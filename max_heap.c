#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at 'index'
void maxHeapify(int arr[], int n, int index) {
    int largest = index;        // Initialize largest as root
    int leftChild = 2 * index + 1;      // Left child = 2*i + 1
    int rightChild = 2 * index + 2;     // Right child = 2*i + 2

    // If left child is larger than root
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // If right child is larger than largest so far
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If largest is not root
    if (largest != index) {
        swap(&arr[index], &arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max-heap
void buildMaxHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIndex = (n / 2) - 1;

    // Perform maxHeapify on each non-leaf node from the last one up to the root
    for (int i = startIndex; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Test the code
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    buildMaxHeap(arr, n);

    printf("Max heap: ");
    printArray(arr, n);

    return 0;
}
