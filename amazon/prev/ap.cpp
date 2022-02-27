int numberOfArithmeticSlices(vector<int>& A) {
    vector<int> lis(A.size(),0);
    if(A.size()<3)
        return 0;
    for(int i=2;i<A.size();i++){
        if(A[i]-A[i-1] == A[i-1]-A[i-2]){
            lis[i] += lis[i-1]+1;
        }
    }
    int ans = 0;
    for(int i=0;i<lis.size();i++)
        ans += lis[i];
    return ans;
} 