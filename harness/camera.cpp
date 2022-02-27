#include <bits/stdc++.h>
using namespace std;
 
#define For(i, st, en) for(int i=st; i<en; i++)
#define ff first
#define ss second
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef long long ll;
 
vi dfs(vvi& g, int i, int p) {
	if (g[i].size() == 1 && p != -1) return {1, 9999, 0};
	int f = 0, s1 = 1, s2 = 0, s3 = 0, s = 9999;
	For (j, 0, g[i].size()) {
		if (g[i][j] == p) continue;
		vi ans = dfs(g, g[i][j], i);
		s1 += min(ans[0], min(ans[1], ans[2]));
		s3 += ans[1];
		if (ans[0] <= ans[1]) f = 1;
		s2 += min(ans[0], ans[1]);
		if (f == 0) s = min(s, ans[0] - ans[1]);
	}
	if (f == 0) s2 += s;
	return {s1, s2, s3};
}
 
int main() {
	int n, m;
	cin>>n>>m;
	vvi g(n);
	For (i, 0, m) {
		int u, v;
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
	vi ans = dfs(g, 0, -1);
	cout<<min(ans[0], ans[1])<<endl;
	return 0;
}