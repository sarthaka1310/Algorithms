/* C++ program for https://www.geeksforgeeks.org/optimal-strategy-for-a-game-set-2/?ref=rp */
#include<iostream>

using namespace std;

#define ll long long
#define N 2005

int dp[N][N];

void reset()//reset the dp array 
{
	for(int j=0;j<N;j++)
		for(int k=0;k<N;k++)
			dp[j][k]=-1;
}

int score(int i, int j, int a[], int pre[]) // gives max score for [i,j]on array a (pre is the prefix sum array for a)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(j==i+1)
		return dp[i][j] = max(a[i], a[j]);

	//debugging
	//cout<<( ((a[i]+pre[j]-pre[i]-score(i+1, j, a, pre))>(a[j]+pre[j]-pre[i]-score(i, j-1, a, pre)))?i:j)<<" in "<<i<<" , "<<j<<endl; 
	//cout<<max( (a[i]+pre[j]-pre[i]-score(i+1, j, a, pre)), (a[j]+pre[j]-pre[i]-score(i, j-1, a, pre)) )<<endl;
	
	return dp[i][j] = max( (a[i]+pre[j]-pre[i]-score(i+1, j, a, pre)), (a[j]+pre[j]-pre[i]-score(i, j-1, a, pre)) );
	//a[i]+pre[j]-pre[i] is the sum of elements in [i,j]
	//hence max(sum(i,j)-score(i+1,j), sum(i,j)-score(i,j-1))
}

int main()
{
  	//input
	int n;
	cout<<"Enter number of elements\n";
	cin>>n;
	int a[n];
	for(int i=0; i<n;i++)
		cin>>a[i];

  	//calculate prefix sum
	int pre[n];
	pre[0]=a[0];
	for(int i=1; i<n;i++)
		pre[i]=pre[i-1]+a[i];

	//debugging the prefix sum
	/*
	   cout<<"Prefix sum\n";
	   for(int i=0; i<n;i++)
	   cout<<pre[i]<<" ";
	   cout<<endl;
	   */

	reset();
	cout<<"Max score is :\n";
	cout<<score(0, n-1, a, pre)<<endl;

	return 0;
}


//alternative approach

/*

   int dp[2][N][N];
   void reset()
   {
   for(int i=0;i<2;i++)
   for(int j=0;j<N;j++)
   for(int k=0;k<N;k++)
   dp[i][j][k]=-1;
   }

   int score(int i, int j, int a[])
   {
   if(dp[i][j]!=-1)
   return dp[i][j];

   if(i==j)
   return dp[i][j]=a[i];
   if(i==j-1)
   return dp[i][j]=max(a[i], a[j]);
   if(i>j)
   return dp[i][j]=0;

   return dp[i][j]=max(a[i]+min(score(i+2, j, a), score(i+1, j-1, a)), a[j]+min(score( i+1, j-1, a), score(i, j-2, a)) );
   }
   */
