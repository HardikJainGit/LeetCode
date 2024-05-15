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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
        {
            return {};
        }

        queue <TreeNode*> q;
        q.push(root);
        vector<vector<int>> v;
        int level = 0;

        while(!q.empty())
        {
            int k = q.size();

            v.push_back(vector<int>()); 
            
            for(int i = 0 ;i<k;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                v[level].push_back(cur -> val);

                if(cur->left)q.push(cur -> left);
                if(cur->right)q.push(cur -> right);
            }

            level += 1;
        }
        return v;
    }
};