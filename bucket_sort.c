#include <stdio.h>
#include <stdlib.h>

// Bucket sort function
void bucketSort(int array[], int n) {
    // Find the minimum and maximum elements in the array
    int min_value = array[0];
    int max_value = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
        }
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    // Calculate the range and allocate memory for the buckets
    int range = max_value - min_value + 1;
    int* buckets = (int*)malloc(range * sizeof(int));
    if (buckets == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Initialize all buckets to 0
    for (int i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        buckets[array[i] - min_value]++;
    }

    // Sort the elements using bucket counts
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (buckets[i] > 0) {
            array[index++] = i + min_value;
            buckets[i]--;
        }
    }

    // Free the dynamically allocated memory
    free(buckets);
}

// Function to print an array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Original array: ");
    printArray(array, n);

    // Perform bucket sort
    bucketSort(array, n);

    printf("Sorted array: ");
    printArray(array, n);

    // Free the dynamically allocated memory
    free(array);

    return 0;
}
