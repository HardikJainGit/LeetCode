class Solution {
public:
    class ds
    {
        public:
        long long mx; // Max left
        long long mi; // Min right
        bool isBST;
    };
    ds dfs(TreeNode* root)
    {
        if (!root)
        {
            return {LLONG_MIN, LLONG_MAX, true};
        }

        // Bottom up dfs

        ds l = dfs(root->left);
        ds r = dfs(root->right);

        ds cur;
        
        cur.mx = max(static_cast<long long>(root->val), r.mx);
        cur.mi = min(static_cast<long long>(root -> val) , l.mi);
        
        cur.isBST = l.isBST && r.isBST && (static_cast<long long>(root -> val) > l.mx && static_cast<long long>(root -> val) < r.mi);

        return cur;
    }

    bool isValidBST(TreeNode* root) 
    {
        if(!root -> right && !root -> left)
        {
            return 1;
        }
        return dfs(root).isBST;
    }   
};