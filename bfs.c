#include<stdio.h>
#include<stdlib.h>

int *queue, *visited, rear = -1, front = -1;

int **read(int n);
int isEmpty();
void enqueue(int d);
int dequeue();
void breadthFirstSearch(int **a, int n, int v);

int main()
{
	int n, v;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	queue = (int *)calloc(n, sizeof(int));
	visited = (int *)calloc(n, sizeof(int));
	int **a = read(n);
	printf("Enter the starting vertex: ");
	scanf("%d",&v);
	printf("The BFS traversal is: ");
	breadthFirstSearch(a, n, v);
	printf("\n");

	free(queue);
	free(visited);
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);

	return 0;
}

int **read(int n)
{
	int **mat = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
		mat[i] = (int *)calloc(n, sizeof(int));

	printf("Enter the graph data in matrix form:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	return mat;
}

int isEmpty()
{
	if (rear == front)
		return 1;
	return 0;
}

void enqueue(int d)
{
	rear++;
	queue[rear] = d;
}

int dequeue()
{
	front++;
	return queue[front];
}

void breadthFirstSearch(int **a, int n, int v)
{
	enqueue(v);
	visited[v] = 1;
	printf("%d ", v);
	while (!isEmpty())
	{
		int d = dequeue();
		for (int j = 0; j < n; j++)
		{
			if (a[d][j] == 1 && visited[j] == 0)
			{
				enqueue(j);
				visited[j] = 1;
				printf("%d ", j);
			}
		}
	}
}
