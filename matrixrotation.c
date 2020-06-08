/* C program to rotate or transpose matrix */
#include<stdio.h>

void print(int n, int a[][n])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%*d ", 2, a[i][j]);
		printf("\n");
	}
}

void clock90(int n, int a[][n])
{
	int t,c=1;
	for(int i=0;i<n/2;i++)
		for(int j=i;j<n-1-i;j++)
		{
			t=a[i][j];
			a[i][j]=a[n-1-j][i];
			a[n-1-j][i]=a[n-1-i][n-1-j];
			a[n-1-i][n-1-j]=a[j][n-1-i];
			a[j][n-1-i]=t;
		}
}

void transpose(int n, int a[][n])
{
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
		{
			int t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
}

void init(int n, int a[][n])//initialises a matrix with serial numbers
{
	int c=1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			a[i][j]=c++;
	}
}

int main()
{
	int n=8;
	int a[n][n];
	init(n, a);
	printf("Original matrix:\n");
	print(n, a);
	clock90(n, a);
	printf("Transpose:\n");

	print(n, a);

	return 0;
}
