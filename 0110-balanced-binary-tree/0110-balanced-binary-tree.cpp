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
    void b(TreeNode* root , int &f)
    {
        if(!root)
        {
            return;
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        if(abs(l-r) > 1)
        {
            f = 1;
        } 
        
        b(root->right,f);
        b(root->left,f);
    }
    bool isBalanced(TreeNode* root) {
        int f = 0;
        if(!root)
        {
            return 1;
        }
        b(root,f);
        if(f)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};