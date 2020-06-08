// C program to count the number of inversions using mergesort
#include<stdio.h>
#include<stdlib.h>

int inv=0;

void merge(int a[], int l, int r)
{
	int *t=malloc(sizeof(int)*(r-l+1));
	int i=l,j, m=l+(r-l)/2,cnt=0;
	j=m;

	while(i<m && j<r)
	{
		inv+=(a[i]<=a[j])?0:m-i;
		t[cnt++]=(a[i]<=a[j])?a[i++]:a[j++];
	}
	while(i<m)
		t[cnt++]=a[i++];
	while(j<r)
		t[cnt++]=a[j++];
	
	for(i=0;i<cnt;i++)
		a[l+i]=t[i];

	free(t);
}

void sort(int a[], int l, int r)
{
	if(l+1<r)
	{
		int m=l+((r-l)/2);
		sort(a, l, m);
		sort(a, m, r);
		merge(a, l ,r);
	}
}

int main()
{
	const int N=1000;
	int n,a[N];
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	sort(a,0,n);


	printf("Inversions: %d\n", inv);
	return 0;
}
