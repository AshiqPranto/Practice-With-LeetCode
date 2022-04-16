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
    int sum = 0;
    void dfs(TreeNode* x)
    {
        if(x->right !=nullptr)  dfs(x->right);
        sum+=x->val;
        x->val = sum;
        if(x->left!=nullptr) dfs(x->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return root;
        dfs(root);
        return root;
    }
};