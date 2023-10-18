#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int **MemAlc(int r,int c);
void Read(int **mat,int r,int c);
void Add(int **mat1,int **mat2,int **res,int rs,int cs,int re,int ce);
void Display(int **mat,int r,int c);

void main()
{
	int **mat1,**mat2,**res;
	int n;

label:
	printf("\nEnter the value of n:\n");
	scanf("%d",&n);	
	
	if((int)(log2(n)*10.0)%10!=0)
	{
		printf("Matrix addition using divide & conquer is not possible. Please re-enter correct dimensions.\n");
		goto label; 
	}
	else
	{
		mat1=MemAlc(n,n);
		mat2=MemAlc(n,n);
		res=MemAlc(n,n);
		
		printf("\nEnter the elements of the first matrix:\n");
		Read(mat1,n,n);
		printf("\nEnter the elements of the second matrix:\n");
		Read(mat2,n,n);
		
		Add(mat1,mat2,res,0,0,n-1,n-1);
		
		printf("\nThe elements of the first matrix are as follows:\n");
		Display(mat1,n,n);
		printf("\nThe elements of the second matrix are as follows:\n");
		Display(mat2,n,n);
		printf("\nThe result of addition of the matrices are as follows:\n");
		Display(res,n,n);	
	}
}

int **MemAlc(int r,int c)
{
	int **arr,i;
	
	arr=(int **)calloc(r,sizeof(int *));
	for(i=0;i<r;i++)
	{
		arr[i]=(int *)calloc(c,sizeof(int));
	}
	
	return arr;
}

void Read(int **mat,int r,int c)
{
	int i,j;
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
}

void Add(int **mat1,int **mat2,int **res,int rs,int cs,int re,int ce)
{
	if(re==rs && ce==cs)
	{
		res[rs][cs]=mat1[rs][cs]-mat2[rs][cs];
		return;
	}
	
	//C1=A1+B1
	Add(mat1,mat2,res,rs,cs,(rs+re)/2,(cs+ce)/2);
	
	//C2=A2+B2
	Add(mat1,mat2,res,rs,(cs+ce+1)/2,(rs+re)/2,ce);
	
	//C3=A3+B3
	Add(mat1,mat2,res,(rs+re+1)/2,cs,re,(cs+ce)/2);
	
	//C4=A4+B4
	Add(mat1,mat2,res,(rs+re+1)/2,(cs+ce+1)/2,re,ce);
}

void Display(int **mat,int r,int c)
{
	int i,j;
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}
