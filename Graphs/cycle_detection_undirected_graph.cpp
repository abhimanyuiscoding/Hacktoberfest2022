#include<bits/stdc++.h>
using namespace std;

#define V 4

void addedge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool cycleutil(int v, vector<int> adj[], vector<bool>& vis, int par)
{
   

    vis[v]=true;

    for(auto i: adj[v])
    {
        if(!vis[i])
        {
            if(cycleutil(i,adj,vis,v))
                return true;
        }
        else if(i!= par)
            return true;
    }

    return false;
}
void hasCycle(vector<int> adj[])
{
    vector<bool> vis(V,false);

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(cycleutil(i,adj,vis,-1))
            {
                cout<<"Graph has cycle!"<<endl;
                return;
            }
        }
    }

    cout<<"Graph has no cycle"<<endl;
}
int main()
{
    vector<int> adj[V];
    vector<bool> vis(V, false);

    addedge(0,1, adj);
    addedge(0,2,adj);
    addedge(1,2,adj);
    addedge(2,3,adj);
    
    hasCycle(adj);

    return 0;
}