#include <stdio.h>
#include <stdlib.h>

int **adjMatrix;
int *visited;
int *queue;
int front, rear;

void createGraph(int numVertices);
void addEdge(int startVertex, int endVertex);
void breadthFirstSearch(int startVertex, int numVertices);
void displaySpanningTree(int numVertices);

int main()
{
    int numVertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    createGraph(numVertices);

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    breadthFirstSearch(startVertex, numVertices);
    displaySpanningTree(numVertices);

    return 0;
}

void createGraph(int numVertices)
{
    int i, j;

    adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    for (i = 0; i < numVertices; i++)
        adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));

    visited = (int *)malloc(numVertices * sizeof(int));
    queue = (int *)malloc(numVertices * sizeof(int));
    front = rear = -1;

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
        for (j = 0; j < numVertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

void addEdge(int startVertex, int endVertex)
{
    adjMatrix[startVertex][endVertex] = 1;
    adjMatrix[endVertex][startVertex] = 1;
}

void breadthFirstSearch(int startVertex, int numVertices)
{
    int i, currentVertex;

    visited[startVertex] = 1;
    enqueue(startVertex);

    while (!isEmpty())
    {
        currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (i = 0; i < numVertices; i++)
        {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void displaySpanningTree(int numVertices)
{
    int i;

    printf("\nThe spanning tree using BFS is:\n");

    for (i = 0; i < numVertices; i++)
    {
        if (visited[i])
        {
            printf("%d - %d\n", i, i);
        }
    }
}

int isEmpty()
{
    if (front == rear)
        return 1;
    else
        return 0;
}

void enqueue(int vertex)
{
    queue[++rear] = vertex;
}

int dequeue()
{
    if (front == rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    return queue[++front];
}
