int subCount(int arr[], int n, int k) {
    int mod[k]; 
    memset(mod, 0, sizeof(mod)); 
    int cumSum = 0; 
    for (int i = 0; i < n; i++) { 
        cumSum += arr[i]; 
        mod[((cumSum % k) + k) % k]++; 
    } 
    int result = 0; 
    for (int i = 0; i < k; i++) 
        if (mod[i] > 1) 
            result += (mod[i] * (mod[i] - 1)) / 2; 
    result += mod[0]; 
    return result; 
} 