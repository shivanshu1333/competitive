int Solution::solve(const vector<int> &A) {
    int s=A.size(),ans=2;
    if(s<=1)
        return s;
    for(int i=0;i<s;i++){
        int first=A[i];
        for(int j=i+1;j<s;j++){
            long long last=A[j];
            long long cd=A[j]-A[i];
            int len=2;
            for(int k=j+1;k<s;k++){
                if(A[k]-last==cd){
                    last=A[k];
                    len++;
                }
            }
            ans=max(ans,len);
        }
    }
    return ans;
}

