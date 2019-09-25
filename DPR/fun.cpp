/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* BST(vector<int>& nums, int l, int r, TreeNode* head){
        if(l>r)
            return head;
        int m = l + (r-l)/2;
        if(head == NULL)
            head = new TreeNode(nums[m]);
        tmp = head;
        BST(nums, m+1, r, head->right);
        BST(nums, l, m-1, head->left);
        return head;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* head=NULL;
        int l=0, r= nums.size()-1;
        head = BST(nums, l, r, head);
        return head;
    }
};