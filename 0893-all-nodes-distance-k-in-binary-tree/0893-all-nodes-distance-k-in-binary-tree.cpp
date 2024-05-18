class Solution {
public:
    void dfs_m(TreeNode* root , TreeNode* prev,map<TreeNode*,TreeNode*> &m)
    {
        if(!root)
        {
            return;
        }
        
        m[root] = prev;
        
        dfs_m(root -> left , root , m);
        dfs_m(root -> right , root , m);
    }
    void dist_k(TreeNode* root , map<TreeNode*,TreeNode*>&par ,  unordered_map<TreeNode*, int>&vis , int count , int k , vector<int> &v)
    {
        // visited is necessary otherwise calls won't end
        
        if(!root)
        {
            return;
        }

        if(count == k)
        {
            v.push_back(root -> val);
        }
        
        vis[root]=1;
        
        if(!vis[root->left])
        dist_k(root->left, par, vis , count + 1 , k , v);
          
        if(!vis[root->right])
        dist_k(root->right, par, vis , count + 1 , k , v);
        
        if(!vis[par[root]])
        dist_k(par[root] , par, vis , count + 1 , k , v);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        map<TreeNode* , TreeNode*> m; // Parent Mapping

        TreeNode* fnd = target;

        TreeNode* prev = NULL;

        dfs_m(root , prev, m);

        vector <int> v;

        unordered_map <TreeNode* , int> vis;
        dist_k(fnd , m , vis , 0 , k , v);

        return v;
    }
};
