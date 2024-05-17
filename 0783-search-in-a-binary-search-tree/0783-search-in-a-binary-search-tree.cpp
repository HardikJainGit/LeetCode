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
    void dfs(TreeNode* root , int &target , TreeNode* &fnd)
    {
        if(!root)
        {
            return;
        }    
        if(root -> val == target)
        {
            fnd = root;
        }
        dfs(root -> left , target , fnd);
        dfs(root -> right , target , fnd);
    }
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(!root)
        {
            return NULL;
        }    
        TreeNode* fnd = NULL;
        dfs(root , val , fnd);
        return fnd;
    }
};