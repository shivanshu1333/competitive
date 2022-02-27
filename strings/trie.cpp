#include <bits/stdc++.h>
using namespace std;
const int maxL = 5000;
bool created[maxL];
int e[maxL];
int n[27][maxL];
int sz = 0;

void insert(string s){
	int v = 0;
	for(int i = 0; i < s.length(); i++){
		int c = s[i] - 'a';
		if(!created[n[c][v]]) {
			n[c][v] = ++sz;
			created[sz] = 1;
		}
		v = n[c][v];
	}
	++e[v];
}

int find(string s){
	int v = 0;
	for(int i=0; i<s.length(); i++){
		int c = s[i] - 'a';
		if(!created[n[c][v]]) return false;
		v = n[c][v];
	}
	return e[v] > 0;
}

int main() {
	// your code goes here
	insert("abcd");
	insert("abdf");
	if(find("abc")) cout<<"YES"<<endl;
	else cout<<"loda lele"<<endl;
	return 0;
}