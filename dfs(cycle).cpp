#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
vector<int>g[N];
bool vis[N];
bool dfs(int vertex,int par)
{
	/* Take action on vertex 
	   after entering the vertex node*/
	//cout<<vertex<<endl;
	bool isloopexist=false;
	vis[vertex]=true;
	for( int child : g[vertex]){
		//cout<<"par "<<vertex<<"child "<<child<<endl;
	    /* Take action on child 
	    before entering the child node*/
	    if(vis[child] && child==par) continue;
	    if(vis[child]) return true;
	    cout<<child<<endl;
	    //cout<<"par "<<vertex<<"child "<<child<<endl;
	    isloopexist |=dfs(child,vertex);
	    /* Take action on child 
	    after exiting the child node*/
	}
	/* Take action on vertex 
	   before exiting the vertex node*/
	return isloopexist;
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
	dfs(1,0);
}
