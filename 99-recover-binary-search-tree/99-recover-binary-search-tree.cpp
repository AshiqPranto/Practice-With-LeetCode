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

    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode*  first = new TreeNode(INT_MIN);
    TreeNode* second;
    
    void dfs(TreeNode* x)
    {
        if(x->left!=nullptr) dfs(x->left);
        if(x->val < prev->val)
        {
            if(first->val==INT_MIN)
            {
                first = prev;
            }
            second = x;
        }
        prev = x;
        if(x->right!=nullptr) dfs(x->right);
    }
    
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};