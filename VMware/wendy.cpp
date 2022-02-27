string solve(string s) {
	int n = s.length();
	int i = 0;
	int w = 0, b = 0;
	while(i < n) {
		int j = i+1;
		while(j < n && s[j] == s[i]) j++;
		if(j-i > 2) {
			if(s[i] == 'w') w += (j-i-2);
			else b += (j-i-2);
		}
		i = j;
	}
	if(b >= w) return "bob";
	return "wendy";
}

int main() {
	// your code goes here
	string s; cin >> s;
	cout << solve(s) << endl;
	return 0;
}