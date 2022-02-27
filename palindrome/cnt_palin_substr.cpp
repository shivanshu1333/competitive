// C++ program to count all distinct palindromic substrings of a string. 
#include <bits/stdc++.h> 
using namespace std; 
int countPalindromes(string s) {
	unordered_map<string, int> m; 
	for (int i = 0; i < s.length(); i++) { 
		for (int j = 0; j <= i; j++) { 
			if (!s[i + j]) 
				break; 
			if (s[i - j] == s[i + j]) { 
				if ((i + j + 1) - (i - j) > 1) 
					m[s.substr(i - j, 
						(i + j + 1) - (i - j))]++; 
			} else
				break; 
		} 
		for (int j = 0; j <= i; j++) { 
			if (!s[i + j + 1]) 
				break; 
			if (s[i - j] == s[i + j + 1]) { 
				if ((i + j + 2) - (i - j) > 1) 
					m[s.substr(i - j, 
						(i + j + 2) - (i - j))]++; 

			} else
				break; 
		} 
	} 
	return m.size(); 
} 
int main(){ 
	string s = "tacocat"; 
	cout << countPalindromes(s) << endl; 
	return 0; 
}