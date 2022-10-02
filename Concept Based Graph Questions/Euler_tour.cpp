// Eular tour type question !!
// --> We are using euler tour to calculate intime and outtime of a node in graph!! It is very useful concept in graph

#include<bits/stdc++.h>
using namespace std;
const int N =1e5;
vector<int>g[N];
vector<int> In(N);
vector<int> Out(N);
int timer=1;
void dfs(int i,int par,vector<int> &In,vector<int> &Out){
	In[i]=timer++;
	for(auto ch:g[i]){
		if(ch==par)continue;
		dfs(ch,i,In,Out);
	}
	Out[i]=timer++;
}

bool check(int x,int y){
	if(In[x]>In[y] && Out[x]<Out[y])return true;
	return false;
}
int main(){
	int n;
	cin>>n;
	for(int i =0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> In(n+1);
	vector<int> Out(n+1);
	dfs(1,-1,In,Out);
	int q;
	cin>>q;
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		if(!check(c,b) && !check(b,c)){
			cout<<"NO"<<endl;
			continue;
		}
		if(a==0){
			if(check(c,b))cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}else{
			if(check(b,c))cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		
	}

}
