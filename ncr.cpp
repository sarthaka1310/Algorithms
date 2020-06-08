/* C++ program to find nCr%m */
#include<iostream>
#include<cstdio>	

using namespace std;

#define ll long long
#define N 1010
#define R 1010

ll dp[N][R];

ll compute(int n, int r, ll m)
{
	if(dp[n][r]!=-1)
		return dp[n][r];
	if(r>n)
		return dp[n][r]=0;
	if(r==0||r==n)
		return dp[n][r]=1%m;

	return dp[n][r]=(compute(n-1, r, m)+compute(n-1,r-1, m))%m;
}

void reset()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<R;j++)
			dp[i][j]=-1;
}

int main()
{
	int n,r,q;
	ll m;
	scanf("%d",&q);
	while(q--)
	{
		reset();
		scanf("%d",&m);
		for(int i=0;i<1000;i++)
		for(int j=0;j<=i;j++)
		{
			scanf("%d %d",&n, &r);
			printf("%lld\n", compute(n, r, m));
		}
	}

	return 0;
}
