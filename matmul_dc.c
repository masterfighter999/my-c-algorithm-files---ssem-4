#include<stdio.h>
#include<stdlib.h>

int **memAlc(int r,int c);
void read(int **mat,int r,int c);
void mult(int **a,int **b,int **c,int rs1,int cs1,int re1,int ce1,int rs2,int cs2,int re2,int ce2,int rs3,int cs3,int re3,int ce3);
void display(int **mat,int r,int c);

void main()
{
	int **mat1,**mat2,**res;
	int m,n;
	printf("Enter the size of matrix\n");
	scanf("%d", &n);
	mat1 = memAlc(n,n);
	mat2 = memAlc(n,n);
	res = memAlc(n,n);
	printf("Enter the elements of first matrix\n");
	read(mat1,n,n);
	printf("Enter the elements of second matrix\n");
	read(mat2,n,n);
	mult(mat1, mat2, res, 0, 0, n-1, n-1, 0, 0, n-1, n-1, 0, 0, n-1, n-1);
	printf("The resultant matrix is \n");
	display(res, n, n);
}

int **memAlc(int r,int c)
{
	int **arr,i;
	arr=(int **)calloc(r,sizeof(int *));
	for(i=0;i<r;i++)
		arr[i]=(int *)calloc(c,sizeof(int));
	
	return arr;
}

void read(int **mat,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&mat[i][j]);
}

void mult(int **a,int **b,int **c,int rs1,int cs1,int re1,int ce1,int rs2,int cs2,int re2,int ce2,int rs3,int cs3,int re3,int ce3)
{
	if(rs1 == re1 && cs1 == ce1 && rs2 == re2 && cs2 == ce2)
	{
		c[rs3][cs3]+=a[rs1][cs1]*b[rs2][cs2];
		return;
	}
	//C11=A11*B11+A12*B21
	mult(a,b,c,rs1,cs1,(rs1+re1)/2,(cs1+ce1)/2,rs2,cs2,(rs2+re2)/2,(cs2+ce2)/2,rs3,cs3,(rs3+re3)/2,(cs3+ce3)/2);
	mult(a,b,c,rs1,(cs1+ce1+1)/2,(rs1+re1)/2,ce1,(rs2+re2+1)/2,cs2,re2,(cs2+ce2)/2,rs3,cs3,(rs3+re3)/2,(cs3+ce3)/2);
	
	//C12=A11*B12+A12*B22
	mult(a,b,c,rs1,cs1,(rs1+re1)/2,(cs1+ce1)/2,rs2,(cs2+ce2+1)/2,(rs2+re2)/2,ce2,rs3,(cs3+ce3+1)/2,(rs3+re3)/2,ce3);
	mult(a,b,c,rs1,(cs1+ce1+1)/2,(rs1+re1)/2,ce1,(rs2+re2+1)/2,(cs2+ce2+1)/2,re2,ce2,rs3,(cs3+ce3+1)/2,(rs3+re3)/2,ce3);
	
	//C21=A21*B11+A22*B21
	mult(a,b,c,(rs1+re1+1)/2,cs1,re1,(cs1+ce1)/2,rs2,cs2,(rs2+re2)/2,(cs2+ce2)/2,(rs3+re3+1)/2,cs3,re3,(cs3+ce3)/2);
	mult(a,b,c,(rs1+re1+1)/2,(cs1+ce1+1)/2,re1,ce1,(rs2+re2+1)/2,cs2,re2,(cs2+ce2)/2,(rs3+re3+1)/2,cs3,re3,(cs3+ce3)/2);
	
	//C22=A21*B12+A22*B22
	mult(a,b,c,(rs1+re1+1)/2,cs1,re1,(cs1+ce1)/2,rs2,(cs2+ce2+1)/2,(rs2+re2)/2,ce2,(rs3+re3+1)/2,(cs3+ce3+1)/2,re3,ce3);
	mult(a,b,c,(rs1+re1+1)/2,(cs1+ce1+1)/2,re1,ce1,(rs2+re2+1)/2,(cs2+ce2+1)/2,re2,ce2,(rs3+re3+1)/2,(cs3+ce3+1)/2,re3,ce3);
}
void display(int **mat,int r,int c)
{
	int i,j;
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}
