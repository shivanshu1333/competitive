//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//   };
TreeNode* dfs(vector<int> &nums, int l, int h){
    if(l>h)
        return NULL;
    int m = l-(l-h)/2;
    TreeNode* root = new TreeNode(nums[m]);
    root->right = dfs(nums, m+1,h);
    root->left = dfs(nums, l, m-1);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size()-1);
}