/* C++ program to find the lcs length or the lcs itself */
#include<iostream>
#include<string>

using namespace std;

#define ll long long 
#define N 1010
#define M 1010

int dp[N][M];

void reset()
{
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			dp[i][j]=-1;
}

int lcs(string a, string b, int i, int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];

	if(i==a.length()||j==b.length())
		return dp[i][j]=0;

	return dp[i][j]=(a[i]==b[j])?(1 + lcs(a, b, i+1, j+1)): max(lcs(a, b, i+1, j), lcs(a, b, i, j+1));
}

string DP[N][M];
string printlcs(string a, string b, int i, int j)
{
	string s="",r="";
	if(i==a.length()||j==b.length())
		return DP[i][j]="";
	if(DP[i][j]!="")
		return DP[i][j];

	if(a[i]==b[j])
		return DP[i][j]=(a[i]+printlcs(a, b, i+1, j+1));

	s=printlcs(a, b, i+1, j);
	r=printlcs(a, b, i, j+1);

	return DP[i][j]=( (s.length()<r.length())?r:s );
}

int main()
{
	string a,b;
	cout<<"Enter string 1:\n";
	cin>>a;
	cout<<"Enter string 2:\n";
	cin>>b;
	cout<<"Enter 1 for length of lcs and 2 for printing lcs\n";
	int n;
	cin>>n;

	if(n==1)
	{
		reset();
		cout<<"Length of Longest common subsequence:"<<lcs(a, b, 0, 0)<<endl;
	}
	else if(n==2)
		cout<<"The LCS is "<<printlcs(a, b, 0, 0)<<endl;
	else
		cout<<"Invalid"<<endl;

	return 0;
}
