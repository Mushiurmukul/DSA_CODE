#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int A[n+10],output[n+10];
	int a=-99999;
	int b=99999;
	//int B[50000];
	map<int,int>B;

	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(A[i]>a)
		{
			a=A[i];
		}
		if(A[i]<b)
		{
			b=A[i];
		}
		B[A[i]]++;
	}
	for(int i=b+1;i<=a;i++)
	{
		B[i]+=B[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		output[--B[A[i]]]=A[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<output[i]<<" ";
	}
}