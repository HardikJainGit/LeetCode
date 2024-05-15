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

//Pre Order NLR (DFS)
//Post Order LRN
//In Order LNR

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        inorderHelper(root, v);
        return v;
    }

    void inorderHelper(TreeNode* node, vector<int>& v) 
    {
        if (node == nullptr) 
        {
            return;
        }
        inorderHelper(node->left, v);
        v.push_back(node->val);
        inorderHelper(node->right, v);
    }
};
