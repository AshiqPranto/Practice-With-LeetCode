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
    TreeNode* convertBST(TreeNode* root) {
        vector<int> a;
        TreeNode* temp = root;
        queue<TreeNode*> q;
        q.push(temp);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp==nullptr) return root;
            a.push_back(temp->val);
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
        sort(a.begin(),a.end());
        vector<int>cumsum(a.size(),0);
        if(a.size()>0) cumsum[a.size()-1] = a[a.size()-1];
        for(int i = a.size()-2;i>=0;i--)
        {
            cumsum[i] = cumsum[i+1]+a[i];
        }
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            int index = upper_bound(a.begin(),a.end(),temp->val)-a.begin();
            if(index<a.size()) 
            {
                temp->val = cumsum[index]+temp->val;
            }
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
        return root;
        
    }
};