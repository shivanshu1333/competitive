#include<bits/stdc++.h> 
using namespace std; 

int minSwaps(vector<int> A) 
{ 
	int n = A.size();
	reverse(A.begin(), A.end());
	
	pair<int, int> AP[n]; 
	for (int i = 0; i < n; i++) { 
		AP[i].first = A[i]; 
		AP[i].second = i; 
	}
	sort(AP, AP + n); 
	
	vector<bool> vis(n, false); 
	int ans = 0; 
	for (int i = 0; i < n; i++) {
		if (vis[i] || AP[i].second == i) continue; 
		int csz = 0; 
		int j = i; 
		while (!vis[j]) { 
			vis[j] = 1; 
			j = AP[j].second; 
			csz++; 
		}
		if (csz > 0) ans += (csz - 1); 
	}
	return ans; 
} 

int main() { 
	vector<int> A = {4, 3, 1, 2, 4};
	cout << minSwaps(A); 
	return 0; 
}