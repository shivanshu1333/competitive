    #include <bits/stdc++.h>
    using namespace std;
     
    int q(vector<vector<pair<int, int>>>& a, vector<int>& c, int i, int p, int s) {
    	int an = 1;
    	for (int j = 0; j < a[i].size(); j++) {
    		if (a[i][j].first == p) continue;
    		if (s + a[i][j].second <= c[a[i][j].first]) {
    			an += q(a, c, a[i][j].first, i, max(0, s + a[i][j].second));
    		}
    	}
    	return an;
    }
     
    int main() {
    	int n;
    	cin>>n;
    	vector<int> c(n);
    	for (int i = 0; i < n; i++) cin>>c[i];
    	vector<vector<pair<int, int>>> a(n);
    	for (int i = 0; i < n-1; i++) {
    		int p, s;
    		cin>>p>>s;
    		a[i+1].push_back({p-1, s});
    		a[p-1].push_back({i+1, s});
    	}
    	int ll = q(a, c, 0, -1, 0);
    	cout<<n-ll<<endl;
    	return 0;
    }

