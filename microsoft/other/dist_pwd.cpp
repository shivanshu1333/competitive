#include <bits/stdc++.h>
using namespace std;
// 2
// abcd bacd cbad cdab ans=2
int main() {
	int n;
	cin >> n;
	string arr[n];
	for (int i=0; i<n; i++)
		cin >> arr[i];
	vector < vector <int>> check;
	check.resize (26, vector <int> (2, 0));
	map < vector < vector <int> >, int > mp;
	for (int i=0; i<n; i++){
		for (int j=0; j<arr[i].size(); j++){
			check[arr[i][j] - 'a'][j%2]++;
		mp[check]++;
	}
	cout << mp.size();
	return 0;
}