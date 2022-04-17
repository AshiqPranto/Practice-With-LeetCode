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
    
    // TreeNode* temp,ans;
    TreeNode* temp = new TreeNode();
    TreeNode* ans = temp;
    
    void dfs(TreeNode* x)
    {
        if(x->left!=nullptr)
        {
            dfs(x->left);
            // temp->left = new TreeNode();
        }
        temp->right = new TreeNode(x->val);
        temp = temp->right;
        
        if(x->right!=nullptr)
        {
            dfs(x->right);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        return ans->right;
    }
};