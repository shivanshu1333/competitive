// CPP program to find the lexicographically 
// maximum substring. 
#include <bits/stdc++.h> 
using namespace std; 

string LexicographicalMaxString(string str) {
	string msub = ""; 
	for (int i = 0; i < str.length(); ++i) 
		msub = max(msub, str.substr(i)); 

	return msub; 
} 

// Driver code 
int main() 
{ 
	string str = "ababaa"; 
	cout << LexicographicalMaxString(str); 
	return 0; 
} 
