#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
vector<int>g[N];
bool vis[N];
void dfs(int vertex)
{
	/* Take action on vertex 
	   after entering the vertex node*/
	//cout<<vertex<<endl;
	vis[vertex]=true;
	for( int child : g[vertex]){
		//cout<<"par "<<vertex<<"child "<<child<<endl;
	    /* Take action on child 
	    before entering the child node*/
	    if(vis[child]) continue;
	    //cout<<child<<endl;
	    //cout<<"par "<<vertex<<"child "<<child<<endl;
	    dfs(child);
	    /* Take action on child 
	    after exiting the child node*/
	}
	/* Take action on vertex 
	   before exiting the vertex node*/
}
int main()
{
	int n,m,count=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			count++;
		}
	}
	cout<<count<<endl;
}
