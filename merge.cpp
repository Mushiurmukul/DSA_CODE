#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int A[N];
int temp[N];
void merge(int l,int h,int mid)
{
	int i=l;
	int j=mid+1;
	int k=l;
	while(i<=mid && j<=h)
	{
		if(A[i]<=A[j])
		{
			temp[k]=A[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=A[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		temp[k]=A[i];
		i++;
		k++;
	}
	while(j<=h)
	{
		temp[k]=A[j];
		j++;
		k++;
	}
}
void mergeSort(int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		mergeSort(l,mid);
		mergeSort(mid+1,h);
		merge(l,h,mid);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	mergeSort(0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<temp[i]<<" ";
	}
}