#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

int **adj; // adjacency matrix
bool *visited; // array to keep track of visited vertices
int *parent; // array to keep track of parent of each vertex
int n; // number of vertices
int numEdges; // number of edges

// function to push element onto stack
void push(int *stack, int vertex, int *top, int *size) {
    if (*top == *size - 1) {
        // if stack is full, double the size of stack
        *size *= 2;
        stack = (int*)realloc(stack, (*size) * sizeof(int));
    }
    stack[++(*top)] = vertex;
}

// function to remove and return top element from stack
int pop(int *stack, int *top) {
    return stack[(*top)--];
}

// function to check if stack is empty
bool isEmpty(int top) {
    return top == -1;
}

// function to find the parent of a vertex
int findParent(int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return findParent(parent[vertex]);
}

// function to perform union of two sets
void unionSets(int x, int y) {
    int xParent = findParent(x);
    int yParent = findParent(y);
    parent[yParent] = xParent;
}

// comparison function for sorting edges based on weight
int compare(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// function for Kruskal's algorithm
void kruskalMST() {
    Edge* edges = (Edge*)malloc(numEdges * sizeof(Edge));
    int i, j;
    int edgeIndex = 0;

    // create a list of all edges from the adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (adj[i][j] != 0) {
                edges[edgeIndex].src = i;
                edges[edgeIndex].dest = j;
                edges[edgeIndex].weight = adj[i][j];
                edgeIndex++;
            }
        }
    }

    // sort the edges in ascending order of weight
    qsort(edges, numEdges, sizeof(Edge), compare);

    // create a parent array to keep track of the parent of each vertex
    parent = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("Minimum Spanning Tree Edges:\n");

    // process each edge in sorted order
    for (i = 0; i < numEdges; i++) {
        int srcParent = findParent(edges[i].src);
        int destParent = findParent(edges[i].dest);

        // check if including this edge creates a cycle
        if (srcParent != destParent) {
            printf("%d -- %d\tWeight: %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            // include this edge in the minimum spanning tree
            unionSets(srcParent, destParent);
        }
    }

    free(edges);
    free(parent);
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // dynamically allocate memory for adjacency matrix and visited array
    adj = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }
    visited = (bool*)calloc(n, sizeof(bool));

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] != 0) {
                numEdges++;
            }
        }
    }

    kruskalMST();

    // free dynamically allocated memory
    free(visited);
    for (i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);

    return 0;
}
