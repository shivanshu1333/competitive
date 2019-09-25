    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	int n, m;
    	cin>>n>>m;
    	vector<vector<int>> a(n, vector<int>(n));
    	for (int i = 0; i < m; i++) {
    		int s, e;
    		cin>>s>>e;
    		a[s-1][e-1] = 1;
    		a[e-1][s-1] = 1;
    	}
    	vector<int> v(n);
    	queue<int> q;
    	v[0] = 1;
    	q.push(0);
    	int l = 0, fl = 0;
    	while (!q.empty()) {
    		int nn = q.size();
    		while (nn-- > 0) {
    			int x = q.front();
    			q.pop();
    			if (x == n-1) {
    				fl = 1;
    				break;
    			}
    			for (int i = 0; i < n; i++) {
    				if (a[0][n-1] == 1 && a[x][i] == 0 && v[i] == 0) {
    					v[i] = 1;
    					q.push(i);
    				} 
                    // else if (a[0][n-1] == 0 && a[x][i] == 1 && v[i] == 0) {
    				// 	v[i] = 1;
    				// 	q.push(i);
    				// }
    			}
    		}
    		if (fl == 1) break;
    		l++;
    	}
    	if (fl == 0) cout<<-1<<endl;
    	else cout<<l<<endl;
    	return 0;
    }