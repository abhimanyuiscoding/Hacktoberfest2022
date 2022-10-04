#include<bits/stdc++.h>
using namespace std;

#define V 4

void addedge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}

void dfs(int v, vector<bool>& vis, vector<int> adj[])
{
    if(vis[v]) return;

    cout<<v<<" ";
    vis[v]=true;

    for(auto u: adj[v])
    {
        dfs(u, vis, adj);
    }

}
int main()
{
    vector<int> adj[V];
    vector<bool> vis(V, false);

    addedge(0,1, adj);
    addedge(0,2,adj);
    addedge(1,2,adj);
    addedge(2,0, adj);
    addedge(2,3,adj);
    addedge(3,3,adj);

    dfs(2, vis, adj);

    return 0;
}