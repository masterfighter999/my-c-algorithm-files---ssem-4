#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int **adj;
bool *visited;
int **spanningTree;
int n;

void dfs(int vertex)
{
    visited[vertex] = true;

    printf("%d ", vertex); // Print the normal traversal

    for (int i = 0; i < n; i++)
    {
        if (adj[vertex][i] == 1 && !visited[i])
        {
            spanningTree[vertex][i] = 1;
            spanningTree[i][vertex] = 1;
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    adj = (int **)malloc(n * sizeof(int *));
    spanningTree = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(n * sizeof(int));
        spanningTree[i] = (int *)malloc(n * sizeof(int));
    }
    visited = (bool *)calloc(n, sizeof(bool));

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
            spanningTree[i][j] = 0; // Initialize the spanning tree matrix
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("Depth First Traversal: ");
    dfs(start);
    printf("\n");

    printf("Spanning tree using Depth First Search:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", spanningTree[i][j]);
        }
        printf("\n");
    }

    free(visited);
    for (i = 0; i < n; i++)
    {
        free(adj[i]);
        free(spanningTree[i]);
    }
    free(adj);
    free(spanningTree);

    return 0;
}
