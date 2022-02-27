void dfs(vector<int>& nums, int &cnt, int i, int sum, int S){
    if(i==nums.size() && sum==S){
        cnt++;
        return;
    }
    if(i==nums.size())
        return;
    
    dfs(nums, cnt, i+1, sum+nums[i],S);
    dfs(nums,cnt,i+1, sum-nums[i],S);
    return;
}

int findTargetSumWays(vector<int>& nums, int S) {
    int cnt = 0;
    int sum = 0;
    dfs(nums, cnt, 0, sum, S);
    return cnt;
}