int maxSubArray(vector<int>& nums) {    
    int msf = nums[0];  
    int meh = nums[0];  
    for(int i=1;i<nums.size();i++){ 
        meh = max(nums[i], meh+nums[i]);    
        msf = max(meh,msf); 
    }   
return msf; 
}
int maxProduct(vector<int>& n) {
    int ans=n[0], mip=n[0], mp=n[0];
    for(int i=1;i<n.size();i++){
        if(n[i]<0)
            swap(mip, mp);
        mip= min(n[i], mip*n[i]);
        mp = max(n[i], mp*n[i]);
        if(mp>ans) ans=mp;
    }
    return ans;
}