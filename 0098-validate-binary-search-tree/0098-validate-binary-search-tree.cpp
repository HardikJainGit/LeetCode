class Solution {
public:
    void dfs(TreeNode* root, int &f, long long mi, long long mx)
    {
        if (!root)
        {
            return;
        }

        if (root->val <= mi || root->val >= mx)
        {
            f = 1;
        }

       // When going to left ensure lesser than root -> val

        dfs(root->left, f, mi, root->val);  

        // When going to right ensure greater than root -> val

        dfs(root->right, f, root->val, mx);
    }

    bool isValidBST(TreeNode* root) 
    {
        if(!root -> right && !root -> left)
        {
            return 1;
        }
        int f = 0;
        long long mx = LLONG_MAX;
        long long mi = LLONG_MIN;
        dfs(root,f,mi,mx);
        return !f;
    }   
};
