#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at 'index'
void minHeapify(int arr[], int n, int index) {
    int smallest = index;        // Initialize smallest as root
    int leftChild = 2 * index + 1;      // Left child = 2*i + 1
    int rightChild = 2 * index + 2;     // Right child = 2*i + 2

    // If left child is smaller than root
    if (leftChild < n && arr[leftChild] < arr[smallest])
        smallest = leftChild;

    // If right child is smaller than smallest so far
    if (rightChild < n && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    // If smallest is not root
    if (smallest != index) {
        swap(&arr[index], &arr[smallest]);

        // Recursively heapify the affected sub-tree
        minHeapify(arr, n, smallest);
    }
}

// Function to build a min-heap
void buildMinHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIndex = (n / 2) - 1;

    // Perform minHeapify on each non-leaf node from the last one up to the root
    for (int i = startIndex; i >= 0; i--)
        minHeapify(arr, n, i);
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

    buildMinHeap(arr, n);

    printf("Min heap: ");
    printArray(arr, n);

    return 0;
}
