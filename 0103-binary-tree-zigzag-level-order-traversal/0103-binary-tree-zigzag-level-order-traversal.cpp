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
    void dfs(TreeNode* node,vector<vector<int>> &r,int level , vector<bool> &dir)
    {
        if(!node)
        {
            return;
        }

        if(level >= r.size())
        {
            r.push_back({});
            dir.push_back(level % 2);
        }

        if (!dir[level])
        {
            r[level].push_back(node->val);
        }
        else
        {
            r[level].insert(r[level].begin(), node->val);
        }
        dfs(node->left,r,level+1,dir);
        dfs(node->right,r,level+1,dir);

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<bool> dir;
        vector<vector<int>> res;
        dfs(root,res,0,dir);
        return res;
    }
};