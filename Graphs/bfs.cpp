#include<bits/stdc++.h>
using namespace std;

#define V 4

void addedge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}

void bfs(int v, vector<int> adj[])
{
    queue<int> q;
    vector<bool> vis(V, false);

    q.push(v);
    vis[v]=true;

    while(!q.empty())
    {
        auto el= q.front();
        q.pop();

        cout<<el<<" ";

        for(auto i: adj[el])
        {
            if(!vis[i])
            {
                vis[i];
                q.push(i);
            }
        }
    }
}
int main()
{
    vector<int> adj[V];

    addedge(0,1, adj);
    addedge(0,2,adj);
    addedge(1,2,adj);
    addedge(2,0, adj);
    addedge(2,3,adj);
    addedge(3,3,adj);

    bfs(2, adj);

    return 0;
}