#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum absolute value from an array
int getMaxAbsolute(int array[], int n) {
    int max = abs(array[0]);
    for (int i = 1; i < n; i++) {
        if (abs(array[i]) > max)
            max = abs(array[i]);
    }
    return max;
}

// Function to perform counting sort based on a specific digit
void countingSortByDigit(int array[], int n, int digit) {
    const int radix = 10;
    int count[radix] = {0};
    int *output = (int *)malloc(n * sizeof(int));

    // Calculate the count of elements at each digit position
    for (int i = 0; i < n; i++)
        count[(abs(array[i]) / digit) % radix]++;

    // Calculate the cumulative count
    for (int i = 1; i < radix; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(abs(array[i]) / digit) % radix] - 1] = array[i];
        count[(abs(array[i]) / digit) % radix]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++)
        array[i] = output[i];

    free(output);
}

// Radix sort function
void radixSort(int array[], int n) {
    int max = getMaxAbsolute(array, n);

    // Perform counting sort for each digit position
    for (int digit = 1; max / digit > 0; digit *= 10)
        countingSortByDigit(array, n, digit);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *positiveArray = (int *)malloc(n * sizeof(int));
    int *negativeArray = (int *)malloc(n * sizeof(int));
    int posCount = 0;
    int negCount = 0;

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num >= 0)
            positiveArray[posCount++] = num;
        else
            negativeArray[negCount++] = num;
    }

    radixSort(positiveArray, posCount);
    radixSort(negativeArray, negCount);

    // Merge the sorted positive and negative arrays
    int i = 0, j = negCount - 1;
    while (i < posCount && j >= 0)
        positiveArray[i++] = negativeArray[j--];

    printf("Sorted array: ");
    for (int k = 0; k < posCount; k++)
        printf("%d ", positiveArray[k]);
    printf("\n");

    free(positiveArray);
    free(negativeArray);
    return 0;
}
