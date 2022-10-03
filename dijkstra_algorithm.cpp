#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+10;
const int INF = 1e8+10;
vector<pair<int,int>>graph[N];
void dijkstra(int source){
	/*

The Handshaking Lemma says that in an undirected graph the sum of the degrees of all nodes is exactly two times the sum of the edges. In contrast, in a directed graph the sum of all in-degrees is always equal to the sum of all out-degrees, and both sums are equal to the number of edges./
*/
	/*the number of times st.insert() happens is around O(E) times ig so assume there are what O(E) elements in your set. since you mark a node as visited after traversing its edges, even if it is repeated in the beginning of the set, you dont traverse its edges
so its something like O(E + E log V) or something idk exactly

maybe E log E here since you dont erase duplicates*/
	/*
	well each time you insert some dist[v], there must be an edge between v and some other node u
so each dist[v], can only be inserted once for every adjacent u
so for all dist[v], itll basically be the sum of the number of their adjacent nodes
and sum of degrees of all nodes = O(E)
*/
	//this shit code has O(E + ElogV)
	//using pq and erasing the previous node in the queue will 
	//give a better complexity of O(V+ElogEor something like that)
	//also btw instead if keeping visited you can add if(nodes.first != distance[par]) continue; 
	
	vector<int> distance(N,INF);
	vector<bool> visited(N,false);
	set<pair<int,int>>st;
	st.insert({0,source});
	distance[source] = 0;
	while(st.size()>0){
		auto nodes = *st.begin();
		st.erase(st.begin());
		int par = nodes.second;//parent node
		if(visited[par])continue;
		cout<<par<<" "<<distance[par]<<endl;
		visited[par] = true;
		for(auto child:graph[par]){
			int wt =  child.second;
			int node =  child.first;
			if(distance[node]>distance[par]+ wt){
				distance[node] = distance[par]+wt;
				st.insert({distance[par]+ wt,node});
				//cout<<distance[child.first]<<" "<<child.first<<endl;
			}
		}
	}

}
int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		graph[x].push_back({y,wt});
	}
	dijkstra(1);

	return 0;
}
