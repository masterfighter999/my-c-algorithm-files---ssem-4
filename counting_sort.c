#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    int i, j;

    // Find the maximum and minimum elements in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;

    // Create a count array to store the count of each element
    int* count = (int*)malloc(range * sizeof(int));

    // Initialize the count array with zeros
    for (i = 0; i < range; i++) {
        count[i] = 0;
    }

    // Store the count of each element in the count array
    for (i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    // Modify the count array to store the actual position of each element
    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted output
    int* output = (int*)malloc(n * sizeof(int));

    // Build the sorted output array
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the sorted output array to the original array
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free the dynamically allocated memory
    free(count);
    free(output);
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Counting Sort
    countingSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
