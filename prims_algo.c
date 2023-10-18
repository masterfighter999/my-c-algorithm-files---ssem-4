#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int **adj;       // adjacency matrix
int *key;        // array to store key values
bool *mstSet;    // array to track included vertices in MST
int *parent;     // array to store parent of each vertex
int n;           // number of vertices

// Function to find the vertex with the minimum key value
int findMinKeyVertex()
{
    int minKey = n;
    int minIndex;

    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == false && key[v] < minKey)
        {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the Minimum Spanning Tree
void printMST()
{
    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d    %d\n", parent[i], i, adj[i][parent[i]]);
    }
}

// Function to construct and print the Minimum Spanning Tree using Prim's algorithm
void primMST()
{
    key[0] = 0;       // Set the key value of the first vertex as 0
    parent[0] = -1;  // First node is always the root of MST

    // MST will have n-1 vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = findMinKeyVertex();

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key values and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] && mstSet[v] == false && adj[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST();
}

int main()
{
    int start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the adjacency matrix, key array, mstSet array, and parent array
    adj = (int**)malloc(n * sizeof(int*));
    key = (int*)malloc(n * sizeof(int));
    mstSet = (bool*)malloc(n * sizeof(bool));
    parent = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        adj[i] = (int*)malloc(n * sizeof(int));
        mstSet[i] = false;
        key[i] = n;
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // Perform Prim's algorithm to find the MST
    primMST();

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        free(adj[i]);
    }
    free(adj);
    free(key);
    free(mstSet);
    free(parent);

    return 0;
}
