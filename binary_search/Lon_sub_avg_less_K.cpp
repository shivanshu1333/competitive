int longestSubsequence(int a[], int n, int q[], int m) {
	sort(a, a + n); 
	int sum = 0, b[n]; 
	for (int i = 0; i < n; i++) { 
		sum += a[i]; 
		double av = (double)(sum) / (double)(i + 1); 
		b[i] = ((int)(av + 1));//adding one to make upper_bound_to_work 
	} 
	sort(b, b + n); // Sort array of average  
	for (int i = 0; i < m; i++) { 
		int k = q[i]; 
		int longest = upper_bound(b, b + n, k) - b; 
		cout << "Answer to Query" << i + 1 << ": "<< longest << endl; 
	} 
} 
