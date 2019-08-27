int maxSubArray(vector<int>& nums) {    
    int msf = nums[0];  
    int meh = nums[0];  
    for(int i=1;i<nums.size();i++){ 
        meh = max(nums[i], meh+nums[i]);    
        msf = max(meh,msf); 
    }   
return msf; 
}