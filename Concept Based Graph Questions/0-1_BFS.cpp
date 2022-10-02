

// we can solve by dijkestra's algo also but ,TC inreases by log(n)
// // 0-1 BFS    -->  me vistied array ki jarurat nhi hoti !!
// //           --> time comlexity same as bfs but 2 times!!

#include<bits/stdc++.h>
using namespace std;

const int N =1e5;
const int INF = 1e9;

vector<pair<int,int>>g[N];
vector<int>lev(N,INF);

int bfs(int vertex,int last){
    deque<int>q;
    q.push_back(1);
    lev[1] =0;
    while(!q.empty()){
        int cur = q.front();
        q.pop_front();
        for(auto &child : g[cur]){
            int child_v = child.first;
            int wt = child.second;
            if(lev[cur]+wt<lev[child_v]){
                lev[child_v] = lev[cur]+wt;  
                if(wt==1){
                    q.push_back(child_v);
                }else{
                    q.push_front(child_v);
                }
            }
        }
    }
    return lev[last]==INF ? -1: lev[last];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x==y) continue;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }
    cout<<bfs(1,7);
}

// input 
// 7 7
// 1 2
// 3 2
// 3 4
// 7 4
// 6 2
// 5 6
// 7 5

// output -> 2



