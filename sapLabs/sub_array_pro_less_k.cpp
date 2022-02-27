#define ll long long
int numSubarrayProductLessThanK(vector<int>& n, int k) {
    if(k<=1) return 0;
    int l=0;
    int cnt=0;
    ll p=1;
    for(int r=0;r<n.size();r++){
        p*=n[r];
        while(p>=k){
            p/=n[l];
            l++;
        }
        cnt+=(r-l+1);
    }
    return cnt;
}