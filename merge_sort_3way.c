#include<stdio.h>
#include<stdlib.h>

void merge_sort(int *a, int n);
void merge_asc(int *la, int *ma, int *ra, int *arr, int n);
void display(int *a, int n);

int main()
{
	int n, ch;
	printf("Enter the size of array\n");
	scanf("%d", &n);
	int *a = (int *)calloc(n, sizeof(int));
	printf("Enter the elements \n");
	for (int i =0; i<n; i++)
		scanf("%d", &a[i]);
	merge_sort(a, n);
	printf("The sorted array is\n");
	display(a, n);
	return 0;
}
void merge_sort(int *a, int n)
{
	if(n<=1) return;
	int las = n/3;
	int mas = (n-las)/2;
	int ras = n-mas-las;
	int *la = (int *)calloc(las, sizeof(int));
	int *ma = (int *)calloc(mas, sizeof(int));
	int *ra = (int *)calloc(ras, sizeof(int));
	int i=0, j=0, k=0;
	while(i<las)
	{
		la[i] = a[i];
		i++;
	}
	while(j<mas)
	{
		ma[j] = a[i];
		j++;
		i++;
	}
	while(k<ras)
	{
		ra[k] = a[i];
		k++;
		i++;
	}
	merge_sort(la, las);
	merge_sort(ma, mas);
	merge_sort(ra, ras);
	merge_asc(la, ma, ra, a, n);
}
void merge_asc(int *la, int *ma, int *ra, int *arr, int n)
{
	int las = n/3;
	int mas = (n-las)/2;
	int ras = n - mas - las;
	int a=0, l=0, m=0, r=0;
	while(l < las && m < mas && r < ras)
	{
		if(la[l] <= ma[m] && la[l] <= ra[r])
		{
			arr[a] = la[l];
			a++;
			l++;
		}
		else if (ma[m] <= la[l] && ma[m] <= ra[r])
		{
			arr[a] = ma[m];
			a++;
			m++;
		}
		else
		{
			arr[a] = ra[r];
			a++;
			r++;
		}
	}
	while(m < mas && r < ras)
	{
		if (ma[m] < ra[r])
		{
			arr[a] = ma[m];
			a++;
			m++;
		}
		else
		{
			arr[a] = ra[r];
			a++;
			r++;
		}
	}
	while(l < las && r < ras)
	{
		if (la[l] < ra[r])
		{
			arr[a] = la[l];
			a++;
			l++;
		}
		else
		{
			arr[a] = ra[r];
			a++;
			r++;
		}
	}
	while(l < las && m < mas)
	{
		if (la[l] < ma[m])
		{
			arr[a] = la[l];
			a++;
			l++;
		}
		else
		{
			arr[a] = ma[m];
			a++;
			m++;
		}
	}
	while(l < las)
	{
		arr[a] = la[l];
		a++;
		l++;
	}
	while(m < mas)
	{
		arr[a] = ma[m];
		a++;
		m++;
	}
	while(r < ras)
	{
		arr[a] = ra[r];
		a++;
		r++;
	}
}

void display(int *a, int n)
{
	for(int i = 0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
