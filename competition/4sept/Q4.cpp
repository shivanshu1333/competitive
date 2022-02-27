    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	int n;
    	cin>>n;
    	vector<int> s(n);
    	int a = 0;
    	for (int i = 0; i < n; i++) {
    		cin>>s[i];
    		if (s[i] < 0) a++;
    	}
    	if (n == 1) {
    		cout<<s[0]<<endl;
    		return 0;
    	}
    	if (a == n) {
    		long long su = 0;
    		for (int i : s) su -= i;
    		int m = *max_element(s.begin(), s.end());
    		cout<<su+2*m<<endl;
    		return 0;
    	}
    	if (a == 0) {
    		long long su = 0;
    		for (int i : s) su += i;
    		int m = *min_element(s.begin(), s.end());
    		cout<<su-2*m<<endl;
    		return 0;
    	}
    	long long su = 0;
    	for (int i : s) if (i < 0) su -= i;
    	else su += i;
    	cout<<su<<endl;
    	return 0;
    }