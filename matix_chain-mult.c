#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
} Matrix;

// Function to perform matrix chain multiplication and return the minimum number of multiplications
int matrixChainMultiplication(Matrix* matrices, int numMatrices) {
    // Create a 2D array to store the minimum number of multiplications for each subproblem
    int** dp = (int**)malloc(sizeof(int*) * numMatrices);
    for (int i = 0; i < numMatrices; i++) {
        dp[i] = (int*)malloc(sizeof(int) * numMatrices);
    }

    // Initialize the diagonal elements with 0, as multiplying a single matrix requires no operations
    for (int i = 0; i < numMatrices; i++) {
        dp[i][i] = 0;
    }

    // Compute the minimum number of multiplications for each chain length
    for (int chainLength = 2; chainLength <= numMatrices; chainLength++) {
        for (int i = 0; i < numMatrices - chainLength + 1; i++) {
            int j = i + chainLength - 1;

            // Initialize dp[i][j] with a large value
            dp[i][j] = INT_MAX;

            // Try each possible split and find the minimum number of multiplications
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + matrices[i].rows * matrices[k].cols * matrices[j].cols;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // Store the minimum number of multiplications required for the entire chain
    int minMultiplications = dp[0][numMatrices - 1];

    // Free the dynamically allocated memory
    for (int i = 0; i < numMatrices; i++) {
        free(dp[i]);
    }
    free(dp);

    return minMultiplications;
}

int main() {
    int numMatrices;
    printf("Enter the number of matrices: ");
    scanf("%d", &numMatrices);

    // Allocate memory for storing the matrices
    Matrix* matrices = (Matrix*)malloc(sizeof(Matrix) * numMatrices);

    // Read the dimensions of the matrices from the user
    for (int i = 0; i < numMatrices; i++) {
        printf("Enter the number of rows of matrix %d: ", i + 1);
        scanf("%d", &(matrices[i].rows));
        printf("Enter the number of columns of matrix %d: ", i + 1);
        scanf("%d", &(matrices[i].cols));
    }

    // Calculate and print the minimum number of multiplications
    int minMultiplications = matrixChainMultiplication(matrices, numMatrices);
    printf("Minimum number of multiplications: %d\n", minMultiplications);

    // Free the dynamically allocated memory
    free(matrices);

    return 0;
}
