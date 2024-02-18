/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    int n;
    queue<TreeNode*> q;
    vector<vector<int>> v;
    q.push(A);
    while(!q.empty()){
        int nc = q.size();
        vector<int> lv;
        while(nc>0){
            TreeNode* top = q.front();
            q.pop();
            nc--;
            lv.push_back(top->val);
            if(top->left != NULL){
                q.push(top->left);
            }
            if(top->right != NULL){
                q.push(top->right);
            }
        }
        v.push_back(lv);
    }
    reverse(v.begin(), v.end());
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            ans.push_back(v[i][j]);
        }
    }
    return ans;
}

