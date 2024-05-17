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
    int count = 0;
    void dfs(TreeNode* root , int k , TreeNode* &kth)
    {
        if(!root)
        {
            return;
        }
        dfs(root -> left , k , kth);
        count +=1;
        if(count == k)
        {
            kth = root;
            return;
        }
        dfs(root -> right , k , kth);

    }
    int kthSmallest(TreeNode* root, int k) 
    {
        if(!root)
        {
            return -1;
        }
        TreeNode* kth = NULL;
        dfs(root , k , kth);
        return kth -> val;
    }
};