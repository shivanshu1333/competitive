#include <bits/stdc++.h>
using namespace std;
// Choose a pair of indices (i, j) such that |i – j| = 1 (indices i and j are adjacent) and set arr[i] = arr[i] + |arr[i] – arr[j]|
int minOperations(int arr[], int n){
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;
	int maxFreq = INT_MIN;
	for (auto x : mp)
		maxFreq = max(maxFreq, x.second);\
	return (n - maxFreq);
}code 
int main()
{
	int arr[] = { 2, 4, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minOperations(arr, n);
	return 0;
}
