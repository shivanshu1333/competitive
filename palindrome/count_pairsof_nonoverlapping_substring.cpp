#include <bits/stdc++.h>
using namespace std;
#define N 100
void pre_process(bool dp[N][N], string s){
	int n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			dp[i][j] = false;
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i <= n - j; i++) {
			if (j <= 2) {
				if (s[i] == s[i + j - 1])
					dp[i][i + j - 1] = true;
			}
			else if (s[i] == s[i + j - 1])
				dp[i][i + j - 1] = dp[i + 1][i + j - 2];
		}
	}
}
int countPairs(string s){
	bool dp[N][N];
	pre_process(dp, s);
	int n = s.length();
	int left[n];
	memset(left, 0, sizeof left);
	int right[n];
	memset(right, 0, sizeof right);
	left[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[j][i] == 1)
				left[i]++;
		}
	}
	right[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		right[i] = right[i + 1];
		for (int j = n - 1; j >= i; j--) {
			if (dp[i][j] == 1)
				right[i]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		ans += left[i] * right[i + 1];
	return ans;
}
int main(){
	string s = "abacaba";
	cout << countPairs(s);
	return 0;
}