class Solution {
public:
    //print kth distance child for each ancestor (pushing into the vector)
    void pk(TreeNode* pa, TreeNode* child, int k, vector<int> &v){
        if(pa == NULL)
            return;
        if(k==0){
            v.push_back(pa->val);
            return;
        }
        if(pa->left != child)
            pk(pa->left, child, k-1,v);
        
        if(pa->right != child)
            pk(pa->right, child, k-1,v);    
        return;
    }
    
    void dfs(TreeNode* root, queue<TreeNode*> &q, TreeNode* target, bool &fl){
        if(root == NULL)
            return;
        if(root == target){
            fl = 1;
            q.push(target);
            return;
        }
        if(fl==0)
            dfs(root->left,q,target,fl);
        if(fl==0)
            dfs(root->right,q,target,fl);
        if(fl == 1) // flag variable to find ancestors
            q.push(root);
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> v;
        TreeNode* cur = root;
        queue<TreeNode*> q; //queue to store all the ancestors of target including target, target being front in the queue
        bool fl = 0;
        dfs(root, q, target, fl);
        TreeNode* child = NULL;
        TreeNode* pa; //parent 
        int cnt = 0; // distance from target
        while(!q.empty()){
            pa = q.front();
            pk(pa,child,K-cnt,v);
            child = pa;
            cnt++;
            q.pop();
        }
        return v;
    }
};