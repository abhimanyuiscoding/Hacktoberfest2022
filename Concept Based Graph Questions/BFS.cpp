
// bfs Code 
// -->>****   queue me jab bhi push kare to
//             usko visit kar de !!!!**

#include<bits/stdc++.h>
using namespace std; 

const int N = 1e5;
vector<int>g[N];
vector<int>vis(N,false);
vector<int>level(N,0);
void bfs(int vertex){
	queue<int>q;
	q.push(vertex);
    vis[vertex] = true;
	while(q.size ()!=0){
		int curr = q.front();
		q.pop();
		for(auto child : g[curr]){
			 if(!vis[child]){
				q.push(child);
				vis[child]=true;
				level[child] = level[curr]+1;
			 }
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[y].push_back(x);
		g[x].push_back(y);
	}
	bfs(1);
	for(int i =1;i<=n;i++){
		cout<<level[i]<<" ";
	}
}

