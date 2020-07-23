// Min heap in C++
#include<iostream>
#include<vector>

using namespace std;

#define ll long long 

void heapify(int i, vector<ll> &v)
{
	if(i>=(v.size()+1)/2)
		return;

	int k=v[2*i]<v[(2*i)+1]?(2*i):(2*i+1);

	if(v[i]>v[k]){
	swap(v[i], v[k]);
	heapify(k, v);
	}
}

void build_heap(vector<ll> &v)
{
	int i=(v.size()+1)/2;
	while(i--)
		heapify(i, v);
}

void insert(ll n, vector<ll> &v)
{
	v.push_back(n);
	int i=v.size()-1;
	while(i && v[i/2]>v[i])
	{
		swap(v[i], v[i/2]);
		i/=2;
	}
}

void extract_min(vector<ll> &v)
{
	v[0]=v[v.size()-1];
	v.pop_back();
	heapify(0, v);
}

ll find_max(const vector<ll> v)
{
	return v[0];
}

int main()
{

	//driver code


	return 0;
}

