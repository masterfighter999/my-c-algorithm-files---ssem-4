#include<stdio.h>
#include<stdlib.h>

int ** Mem_Alc(int r,int c);
void Read(int **arr,int r,int c);
void Display(int **arr,int r,int c);
void Mull(int **arr1,int **arr2,int **arr3,int r1,int c2, int r2);

void main()
{
   	int **arr1,**arr2,**arr3,r1,c1,r2,c2,i,j;  
 Step1:  	printf("\nEnter the number of rows followed by the number of columns of the first matrix:\n");
   	scanf("%d%d",&r1,&c1);
   	
	printf("Enter the number of rows followed by the number of columns of the second matrix:\n");
   	scanf("%d%d",&r2,&c2);

if(c1!=r2)
{
	printf("The matrices can't be multiplied");
	goto Step1;
}

else{
   	arr1=Mem_Alc(r1,c1);
   	arr2=Mem_Alc(r2,c2);
   	arr3=Mem_Alc(r1,c2);
   	
   	printf("\nEnter the elements of the first matrix:\n");
   	Read(arr1,r1,c1);
   	
   	printf("\nEnter the elements of the second matrix:\n");
   	Read(arr2,r2,c2);
   	
   	printf("\nThe elements of the first matrix are as follows:\n");
   	Display(arr1,r1,c1);
   	
   	printf("\nThe elements of the second matrix are as follows:\n");
   	Display(arr2,r2,c2);
   	
   	Mull(arr1,arr2,arr3,r1,c2,r2);
   	
   	printf("\nThe result of multiplication of the two matrices is as follows:\n");
   	Display(arr3,r1,c2);
}
}

int ** Mem_Alc(int r,int c)
{
	int **arr,i;
	
	arr=(int **)calloc(r,sizeof(int *));
	for(i=0;i<r;i++)
   	{
      		arr[i]=(int *)calloc(c,sizeof(int));
   	}
   	return arr;
}

void Read(int **arr,int r,int c)
{
   	int i,j;
   	
   	for(i=0;i<r;i++)
   	{
      		for(j=0;j<c;j++)
      		{
         		scanf("%d",&arr[i][j]);
      		}
   	}
}

void Display(int **arr,int r,int c)
{
   	int i,j;
   	
   	for(i=0;i<r;i++)
   	{
      		for(j=0;j<c;j++)
      		{
         		printf("%d\t",arr[i][j]);
      		}
      		printf("\n");
   	}
}

void Mull(int **arr1,int **arr2,int **arr3,int r1,int c2, int r2)
{
   	int a,b,k;
   	int sum; 

   	for(a=0; a<r1; a++)
	{
		for(b=0; b<c2; b++)
		{
			
			for (k=0; k<r2; k++)
			{
				arr3[a][b]+= arr1[a][k]*arr2[k][b];
			}
		}
	}

	
}