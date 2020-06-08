#include<stdio.h>
#include<stdlib.h>

int** add(int **a, int** b)
{
	if( !a || !b || sizeof(a)!=sizeof(b) || (sizeof(a[0])!=sizeof(b[0])) )
		return NULL;
	
	int n=sizeof(a)/sizeof(a[0]);//number of rows
	int **m=malloc(sizeof(int*)*n);
	for(int i=0; i<n;i++)
		m[i]=malloc(sizeof(int)*(sizeof(a)/n));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n;j++)
			m[i][j]=a[i][j]+b[i][j];
	}

	return m;
}

int **matmul(int n1, int m1, int n2, int m2, int a[][m1], int b[][m2])
{
	if(!n1||!n2||m1!=n2)
		return NULL;

	int **c=malloc(sizeof(int*)*n1);
	for(int i=0; i<n1;i++)
		c[i]=malloc(sizeof(int)*m2);

	for(int i=0; i<m1; i++)
	{
		for(int j=0; j<m2; j++)
		{
			c[i][j]=0;
			for(int k=0;k<m1; k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}

	return c;
}

void printmat(int **a)
{
	printf("rows:%d\n", sizeof(a)/sizeof(a[0]));
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		for(int j=0;j<sizeof(a[0]);j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int mat1[][2] = { { 2, 4 }, { 3, 4 } };
	int mat2[][2] = { { 1, 2 }, { 1, 3 } };

	int **ans=matmul(2,2,2,2,mat1, mat2);

	printf("\n\n\n");

	printmat(ans);

	free(ans);

	return 0;
}
