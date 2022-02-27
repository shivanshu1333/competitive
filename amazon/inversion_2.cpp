// Inversions in an array
//call mergeSort(arr)
typedef vector<int> vi;
int n;
//O(n)
int getInvCount(int arr[], int n){
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
} 
//O(nlog(n))
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