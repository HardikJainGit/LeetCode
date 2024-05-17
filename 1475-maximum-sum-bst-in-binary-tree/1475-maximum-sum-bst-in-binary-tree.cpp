class Solution {
public:
    class ds
    {
        public:
        int mx; // Max left
        int mi; // Min right
        bool isBST;
        int sum;
    };

    ds dfs(TreeNode* root , int &ret)
    {
        if(!root)
        {
            return {INT_MIN , INT_MAX , true , 0};
        }

        // Bottom up dfs

        ds l = dfs(root -> left , ret);
        ds r = dfs(root -> right , ret);

        ds cur;

        if(!root->right)
        {
            cur.mx = max(root -> val , r.mx);
        }
        else
        {
            cur.mx = r.mx;
        }

        if(!root->left)
        {
            cur.mi = min(root -> val , l.mi);
        }
        else
        {
            cur.mi = l.mi;
        }

        // Or use the lines below :

        // cur.mx = max(root -> val , r.mx);
        // cur.mi = min(root -> val , l.mi);
        
        cur.sum = l.sum + r.sum + root -> val;
        cur.isBST = l.isBST && r.isBST && (root -> val > l.mx && root -> val < r.mi);

        if(cur.isBST)
        {
            ret = max(ret , cur.sum);
        }

        return cur;
    }

    int maxSumBST(TreeNode* root) 
    {
        int mx_sum = 0;
        ds temp = dfs(root , mx_sum);
        return mx_sum;
    }
};