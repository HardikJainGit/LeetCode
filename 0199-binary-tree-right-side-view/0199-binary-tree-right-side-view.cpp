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
    void dfs(TreeNode* node , vector <int> &v,int level,map<int,int> &vis)
    {
        if(!node)
        {
            return;
        }
        cout << node->val;
        if(!vis[level])
        {
            vis[level] = 1;
            v.push_back(node->val);
        }
        
        if(node->right)
        {
            dfs(node->right , v,level+1,vis);
        }
        // else
        {
            dfs(node->left,v,level+1,vis);
        }
    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> v;
        if(!root)
        {
            return v;
        }
        v.push_back(root->val);
        map<int,int> vis;
        dfs(root->right,v,0,vis);
        dfs(root->left,v,0,vis);
        return v;   
    }
};