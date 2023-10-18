#include<stdio.h>
#include<stdlib.h>

int **a, n, *visited;

int **create(int n);
void dfs();
void main()
{
	int v;
	printf("Enter the no of vertex\n");
	scanf("%d", &n);
	a = create(n);
	visited = (int *)calloc(n, sizeof(int));
	printf("Enter the starting vertex\n");
	scanf("%d", &v);
	dfs(v);
	printf("\n");
}
int **create(int n)
{
	int **mat = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i< n; i++)
		mat[i] = (int *)calloc(n, sizeof(int));
	printf("Enter the graph in matrix representation\n");
	for(int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			scanf("%d", &mat[i][j]);
	return mat;
}
void dfs(int v)
{
	printf("%d ", v);
	visited[v]=1;
	for (int j = 0; j<n; j++)
	{
		if(a[v][j] == 1 && visited[j]==0)
		{
			dfs(j);
		}
	}
}

