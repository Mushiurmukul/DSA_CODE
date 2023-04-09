#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
vector<int>g[N];
bool vis[N];
int parr[N];
void dfs(int vertex,int par=-1)
{
	parr[vertex]=par;
	/* Take action on vertex 
	   after entering the vertex node*/
	//cout<<vertex<<endl;
	vis[vertex]=true;
	for( int child : g[vertex]){
		//cout<<"par "<<vertex<<"child "<<child<<endl;
	    /* Take action on child 
	    before entering the child node*/
	    if(child==par) continue;
	    //cout<<child<<endl;
	    //cout<<"par "<<vertex<<"child "<<child<<endl;
	    dfs(child,vertex);
	    /* Take action on child 
	    after exiting the child node*/
	}
	/* Take action on vertex 
	   before exiting the vertex node*/
}
vector<int> path(int v)
{
	vector<int> ans;
	while(v !=-1)
	{
		//cout<<v<<" ";
		ans.push_back(v);
		v=parr[v];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1);
	int x,y,lca;
	cin>>x>>y;
	//cout<<x<<y<<endl;
	vector<int> path_x=path(x);
	vector<int> path_y=path(y);
	int minn=min(path_x.size(),path_y.size());
	for(int i=0;i<minn;i++)
	{
		//cout<<path_x[i]<<" "<<path_y[i]<<endl;
		if(path_x[i]==path_y[i])
		{
			lca=path_y[i];
		}
		else
		{
			break;
		}
	}
	cout<<lca<<endl;

}
