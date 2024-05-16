class Solution {
public:
    void dfs(TreeNode* node , int &hm , int h) 
    {
        if (!node) 
        {
            return;
        }

        if (!node->left && !node->right) 
        {
            if(h > hm)
            {
                hm = h;
            }
        } 
        else 
        {
            dfs(node->left , hm , h + 1);
            dfs(node->right , hm , h + 1);
        }
    }
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int hm = INT_MIN;
        dfs(root , hm , 1);
        return hm;
    }
};