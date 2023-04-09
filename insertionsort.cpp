#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll a,i,j,k,n;
	cin>>n;
	ll A[n+10];
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(i=1;i<n;i++)
	{
		k=A[i];
		j=i-1;
		while(j>=0 && A[j]<k)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=k;
	}
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}

}