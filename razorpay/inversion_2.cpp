// Inversions in an array
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n;
int merge(vi &v, vi &aux, int l, int m, int r){
	int i=l, j=m, k=l, invCnt=0;
	k = l;
	while ((i<=m-1) && (j<=r)) {
		if (v[i] <= v[j]) aux[k++] = v[i++];
		else {
			aux[k++] = v[j++];
			invCnt = invCnt+m-i;
		}
	}
	while (i <= m-1) aux[k++] = v[i++];
	while (j <= r) aux[k++] = v[j++];
	for (i = l; i <= r; i++) v[i] = aux[i];
	return invCnt;
}
int _mergeSort(vi &v, vi &aux, int l, int r){
	int m, invCnt = 0;
	if (r>l){
		m = (r+l) / 2;
		invCnt = _mergeSort(v, aux, l, m);
		invCnt += _mergeSort(v, aux, m+1, r);
		invCnt += merge(v, aux, l, m+1, r);
	}
	return invCnt;
}
int mergeSort(vi &v){
    vi aux(n);
	return _mergeSort(v, aux, 0, n-1);
}
int main(){
	vi arr = { 1, 20, 6, 4, 5 };
	n = arr.size();
	int ans = mergeSort(arr);
	cout << " Number of inversions are " << ans;
	return 0;
}