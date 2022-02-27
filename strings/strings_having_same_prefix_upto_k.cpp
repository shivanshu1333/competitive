#include <bits/stdc++.h>
using namespace std;
// Trie node (considering only lowercase alphabets)
struct Node {
	Node* arr[26];
	int freq;
};
Node* insert(string s, Node* root){
	int in;
	Node* cur = root;
	for (int i = 0; i < s.length(); i++) {
		in = s[i] - 'a';
		if (cur->arr[in] == NULL)
			cur->arr[in] = new Node();
		cur->arr[in]->freq++;
		cur = cur->arr[in];
	}
	return root;
}
// Function to return the count of strings
// whose prefix of length k matches with the
// k length prefix of the given string
int find(string s, int k, Node* root){
	int in, count = 0;
	Node* cur = root;
	for (int i = 0; i < s.length(); i++) {
		in = s[i] - 'a';
		if (cur->arr[in] == NULL) return 0;
		cur = cur->arr[in];
		count++;
		if (count == k)
			return cur->freq;
	}
	return 0;
}
int main(){
	string arr[] = { "abba", "abbb", "abbc", "abbd", "abaa", "abca" };
	int n = sizeof(arr) / sizeof(string);
	Node* root = new Node();
	for (int i = 0; i < n; i++)
		root = insert(arr[i], root);
	cout << find("abbg", 3, root) << endl;
	cout << find("abg", 2, root) << endl;
	cout << find("xyz", 2, root) << endl;
	return 0;
}
