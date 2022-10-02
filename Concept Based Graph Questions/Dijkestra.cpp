

// sortest Path find (Dijkestra Algo) !!
// greedy method h dijkestra !!
// we are using priority queue in dijkestra 


#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<pair<int,int>>g[N];
const int INF = 1e9;
vector<int>dist(N,INF);
vector<int>vis(N,0);

void dijkersta(int source){
    set<pair<int,int>>st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0){
        auto node = *st.begin();
        int v_node = node.second;
        int wt1 = node.first;
        st.erase(st.begin());
        if(vis[v_node]) continue;
        vis[v_node] =1;
        for(auto &child : g[v_node]){
            int child_v = child.first;
            int wt2 = child.second;
            if(dist[v_node]+wt2<dist[child_v]){
                dist[child_v] = dist[v_node]+wt2;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}

int main(){
     int n,m;
     cin>>n>>m;
     for(int i =0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
     }
     dijkersta(1);
     for(int i =1;i<=n;i++){
        cout<<dist[i]<<" ";
     }
}

// input                                //output
// 5 7                                 --> 0 3 2 5 4
// 1 2 4
// 1 3 2
// 2 3 1
// 2 4 6
// 2 5 1
// 4 5 1
// 3 5 3








