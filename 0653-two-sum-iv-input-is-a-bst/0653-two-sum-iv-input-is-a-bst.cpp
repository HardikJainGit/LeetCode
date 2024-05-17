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
    void dfs(TreeNode* root , int k , int &f , map<int , int> &m)
    {
        if(!root)
        {
            return;
        }
        if(m.find(k-(root -> val))!=m.end())
        {
            f = 1;
        }
        m[root -> val] = 1;
        dfs(root -> right , k , f ,m);
        dfs(root -> left , k , f , m);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        map<int ,int> m;
        int f = 0;
        dfs(root,k,f,m);
        return f;
    }
};