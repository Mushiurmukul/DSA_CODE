#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,i,j,m,temp;
	cin>>n;
	ll A[n+10];
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]>A[m])
			{
				m=j;
			}
		}
		//swap(A[i],A[m]);
		temp=A[i];
		A[i]=A[m];
		A[m]=temp;
	}
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}