#define N 100
int dp[N][N];
set<string> findLCS(string X, string Y, int m, int n){
	set<string> s;
	if (m == 0 || n == 0){
		s.insert("");
		return s;
	}
	if (X[m - 1] == Y[n - 1]){
		set<string> tmp = findLCS(X, Y, m - 1, n - 1);
		for (string str : tmp)
			s.insert(str + X[m - 1]);
	}
	else{
		if (dp[m - 1][n] >= dp[m][n - 1])
			s = findLCS(X, Y, m - 1, n);
		if (dp[m][n - 1] >= dp[m - 1][n]){
			set<string> tmp = findLCS(X, Y, m, n - 1);
			s.insert(tmp.begin(), tmp.end());
		}
	}
	return s;
}
void printSingle(string X, string Y){
    int m=X.length();
    int n=Y.length();
    int index = dp[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0){
        if (X[i-1] == Y[j-1]){
            lcs[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    cout<<"LCS "<<lcs<<endl;
}
int LCS(string X, string Y, int m, int n){
	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m][n];
}