class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root || root == p || root == q)
        {
            return root;
        }
        
        TreeNode* l = NULL;
        TreeNode* r = NULL;

        if(p -> val < root -> val && q -> val < root -> val)
        {
            l = lowestCommonAncestor(root -> left , p , q);
        }
        else
        {
            r = lowestCommonAncestor(root -> right , p ,q);
        }

        if(!l)
        {
            return r;
        }

        else if(!r)
        {
            return l;
        }

        else if(l && r)
        {
            return root;
        }

        return NULL;
    
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p -> val < root -> val && q -> val > root -> val || p -> val > root -> val && q -> val < root -> val)
        {
            return root;
        }

        return dfs(root , p , q);
    }
};
