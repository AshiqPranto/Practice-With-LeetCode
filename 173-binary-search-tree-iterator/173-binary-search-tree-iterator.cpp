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
class BSTIterator {
public:
    
    vector<int>ans;
    int i = 0;
    void dfs(TreeNode* x)
    {
        if(x->left!=nullptr) dfs(x->left);
        ans.push_back(x->val);
        if(x->right!=nullptr) dfs(x->right);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        int temp = ans[i];
        i++;
        return temp;
        
    }
    
    bool hasNext() {
        if(i<ans.size()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */