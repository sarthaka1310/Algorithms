/* C program to compute a general linear homogenous recursion*/
/* Requires C99 */
#include<stdio.h>

#define ll long long

ll M;

//matrix multiplication
void matmul(ll m1, ll m, ll a[][m], ll n, ll b[][n], ll ans[][n]) // a*b is stored in ans where a is m1xm
{
	ll c[n][n];

	for(ll i=0; i<m1; i++)
	{
		for(ll j=0; j<n; j++)
		{
			c[i][j]=0;
			for(ll k=0;k<m;k++)
				c[i][j]=(c[i][j]+ (a[i][k]*b[k][j])%M )%M;
		}
	}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			ans[i][j]=c[i][j];
}

//matrix exponentiation
void matexp(ll n, ll a[][n], ll p) // a is nxn matrix raised to power p
{
	ll ans[n][n];//temporary identity matrix

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			ans[i][j]=(i==j)?1:0; 

	while(p)
	{
		if(p&1)
			matmul(n, n, ans, n, a, ans);//ans=a*ans

		p>>=1;
		matmul(n, n, a, n, a, a); //squaring a
	}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			a[i][j]=ans[i][j];

}

void printmat(ll n, ll a[][n])//print a nxn matrix 'a'
{
	for(ll i=0;i<n;i++)
	{
		for(ll j=0; j<n;j++)
			printf("%lld ", a[i][j]);
		printf("\n");
	}
}

int main()
{
	ll k, n;
	printf("n - The position in recurrence to be found\nk - The number of base cases\nm - The modulus (Enter -1 if not required)\n");
	printf("Enter n k m:\n");
	scanf("%lld %lld %lld", &n, &k, &M);
	M=M==-1?1000000007:M;

	ll a[k][k], i, j;

	ll I[k][k];

	for(i=0;i<k;i++)
		for(j=0;j<k;j++)
			a[i][j]=I[i][j]=0;

	for(i=0;i<k;i++)
		I[0][i]=I[(i+1)%k][i]=1;

	printf("Enter the coefficients:\n");
	for(i=0;i<k;i++)
		scanf("%lld", &I[0][i]);

	printf("Enter the base values:\n");
	for(i=0;i<k;i++)
		scanf("%lld", &a[i][0]);

	if(n<=k)
		printf("%lld\n", a[n-1][0]%M);
	else
	{
		matexp(k, I, n-k+1);
		matmul(k, k, I, k, a, I);
		printf("%lld\n", I[0][0]%M);
	}

	return 0;
}
