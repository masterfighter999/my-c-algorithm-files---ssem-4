#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i, int k) {
    int largest = i;
    int child;

    for (int j = 1; j <= k; j++) {
        child = k * i + j;

        if (child < n && arr[child] > arr[largest]) {
            largest = child;
        }
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, k);
    }
}

void buildHeap(int *arr, int n, int k) {
    int start = (n / k) - 1;

    for (int i = start; i >= 0; i--) {
        heapify(arr, n, i, k);
    }
}

void heapSort(int *arr, int n, int k) {
    buildHeap(arr, n, k);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, k);
    }
}

void display(int *arr, int n) {
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    heapSort(arr, n, k);

    display(arr, n);

    free(arr);

    return 0;
}
