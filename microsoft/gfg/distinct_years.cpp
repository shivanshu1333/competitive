#include <bits/stdc++.h> 
using namespace std;
int distinct_year(string str) {
	string str2 = ""; 
	unordered_set<string> uniqueDates; 
	for (int i = 0; i < str.length(); i++) { 
		if (isdigit(str[i])) {
			str2.push_back(str[i]); 
		if (str[i] == '-')
			str2.clear(); 
		if (str2.length() == 4) { 
			uniqueDates.insert(str2); 
			str2.clear(); 
		} 
	} 
	return uniqueDates.size(); 
} 
int main() {
	string str = "UN was established on 24-10-1945."
				"India got freedom on 15-08-1947."; 
	cout << distinct_year(str); 
	return 0; 
} 
