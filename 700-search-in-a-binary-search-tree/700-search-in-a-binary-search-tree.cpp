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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->val == val)
            {
                return temp;
            }
            if(temp->left!=nullptr) q.push(temp->left);
            if(temp->right!=nullptr) q.push(temp->right);
        }
        return nullptr;
    }
};