#include <bits/stdc++.h>
using namespace std;
 
int q(vector<vector<pair<int, int>>>& a, vector<int>& s, int i, int p) {
	for (int j = 0; j < a[i].size(); j++) {
		if (a[i][j].first == p) continue;
		int v = a[i][j].first, t = a[i][j].second;
        q(a, s, v, i);
		if (t == 2 && s.size() == 0) {
			s.push_back(v);
		}
	}
	return 0;
}
 
int main() {
	int n;
	cin>>n;
	vector<vector<pair<int, int>>> a(n);
	for (int i = 0; i < n-1; i++) {
		int s, e, t;
		cin>>s>>e>>t;
		a[s-1].push_back({e-1, t});
		a[e-1].push_back({s-1, t});
	}
	vector<int> s;
    q(a, s, 0, -1)
	cout<<s.size()<<endl;
	for (int i : s) cout<<i+1<<" ";
	cout<<endl;
	return 0;