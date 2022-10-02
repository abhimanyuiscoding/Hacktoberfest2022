//kruskal algo ..(sabse chote se start karenge ..)

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int par[N];
int size[N];
void make(int v){
  par[v] =v;
  size[v] = 1;
}
int find(int v){
   if(v = par[v]) return v;
   return find(par[v]);
}
void Union(int a,int b){
  a = find(a);
  b = find(b);
  if(a!=b){
     if(size[b]>size[a]) swap(a,b);
     par[b] =a;
     size[a]+=size[b];
  }

}
int main(){
  int n,m;
  cin>>n>>m;
  for(int i =1;i<=n;i++){
    make(i);
  }
  vector<pair<int,pair<int,int>>>edges;
  for(int i =0;i<m;i++){
      int u,v,w;
      cin>>u>>v>>w;
      edges.push_back({w,{u,v}});
  }
  int cost =0;
  sort(edges.begin(),edges.end());
  for(auto &edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(v)==find(u)) continue;
        Union(u,v);
        cost+=wt;
  }
  cout<<cost<<endl;
}










