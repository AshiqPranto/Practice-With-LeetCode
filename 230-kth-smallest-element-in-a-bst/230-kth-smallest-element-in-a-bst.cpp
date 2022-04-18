/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int globalk;
    int ans = -1;
    int order = 0;
    void dfs(TreeNode* x)
    {
        if(x->left!=nullptr) dfs(x->left);
        order++;
        if(order == globalk && ans==-1) ans = x->val;
        else{
            if(x->right!=nullptr) dfs(x->right);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        globalk = k;
        dfs(root);
        return ans;
    }
};