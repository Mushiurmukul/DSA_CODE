#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,i,j,k;
	cin>>n;
	ll A[n+10];
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(A[j]<A[j+1])
			{
				swap(A[j],A[j+1]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}