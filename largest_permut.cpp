vector<int> largestPermutation(int k, vector<int> arr) {
    vector<int> ans=arr;
    int n=arr.size();
    unordered_map<int, int> m;
    for(int i=0;i<n;i++)
        m[arr[i]]=i;
    int stp=k;
    int i=0;
    while(stp>0 && i<n){
        if(ans[i]==(n-i))
            i++;
        else{
            int tmp;
            tmp=ans[i];
            ans[i]=n-i;
            ans[m[n-i]]=tmp;
            m[tmp]=m[n-i];
            m[n-i]=i;
            stp--;
            i++;
        }
    }
    return ans;
}