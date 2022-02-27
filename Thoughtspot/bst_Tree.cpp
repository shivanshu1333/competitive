struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bst(vector<int> &v, int l, int r){
    if(l>r) return NULL;
    int m = l-(l-r)/2;
    TreeNode* rt = new TreeNode(v[m]);
    rt->left = bst(v, l, m-1);
    rt->right = bst(v, m+1, r);
    return rt;
} 
 
TreeNode* Solution::sortedListToBST(ListNode* A){
    vector<int> v;
    ListNode *T=A;
    while(T!=NULL){
        v.push_back(T->val);
        T=T->next;
    }
    return bst(v, 0, v.size()-1);
}