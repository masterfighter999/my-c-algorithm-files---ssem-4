#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int **adj; // adjacency matrix
bool *visited; // array to keep track of visited vertices
int *stack; // pointer to stack
int top = -1; // top of stack
int size = 0; // size of stack
int n; // number of vertices

// function to push element onto stack
void push(int vertex) {
    if(top == size - 1) {
        // if stack is full, double the size of stack
        size *= 2;
        stack = (int*)realloc(stack, size * sizeof(int));
    }
    stack[++top] = vertex;
}

// function to remove and return top element from stack
int pop() {
    return stack[top--];
}

// function to check if stack is empty
bool isEmpty() {
    return top == -1;
}

// function for depth first search
void dfs(int start) {
    int i, vertex;

    // mark the starting vertex as visited and push it onto stack
    visited[start] = true;
    push(start);

    while(!isEmpty()) {
        // remove and print top element from stack
        vertex = pop();
        printf("%d ", vertex);

        // check all adjacent vertices of the popped vertex
        for(i = 0; i < n; i++) {
            // if an adjacent vertex is not visited, mark it as visited and push it onto stack
            if(adj[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                push(i);
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // dynamically allocate memory for adjacency matrix and visited array
    adj = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }
    visited = (bool*)calloc(n, sizeof(bool));

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // dynamically allocate memory for stack
    size = n;
    stack = (int*)malloc(size * sizeof(int));

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("Depth First Traversal: ");
    dfs(start);

    // free dynamically allocated memory
    free(stack);
    free(visited);
    for(i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);

    return 0;
}
