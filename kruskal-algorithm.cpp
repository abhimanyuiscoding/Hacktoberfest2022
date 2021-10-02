#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second

const ll mod = 1e9 + 7;


class dsu {

	vector<int> par, rank;
	int N;

public:
	
	dsu(int N) {
		this -> N = N;

		par.resize(N);
		rank.resize(N);
		
		for(int i = 0; i < N; ++i) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int get(int x) {
		return par[x] == x ? x : par[x] = get(par[x]);
	}

	void unite(int x, int y) {
		int s1 = get(x);
		int s2 = get(y);

		if(s1 != s2) {

			if(rank[s2] < rank[s1]) {
				par[s2] = s1;
				rank[s1] += rank[s2];
			} else {
				par[s1] = s2;
				rank[s2] += rank[s1];
			}	
		}

		return;
	}

	void output() {
		for(int i = 0; i < N; ++i) {
			printf("%d ", par[i]);
		}puts("");
	}

};


void solve() {
	
	int N, M;
	scanf("%d%d", &N, &M);

	vector<pair<int, pair<int, int> >> edges(M);

	rep(i, 0, M) {
		scanf("%d%d%d", &edges[i].ss.ff, &edges[i].ss.ss, &edges[i].ff);
	}

	sort(all(edges));

	dsu D(N);

	int cost = 0;	

	for(auto x:edges) {
		
		if(D.get(x.ss.ff) != D.get(x.ss.ss)) {
			D.unite(x.ss.ff, x.ss.ss);
			cost += x.ff;
		}
	}

	printf("%d\n", cost);

	return;
}


int main() {

	solve();

	return 0;
}