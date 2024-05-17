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
    TreeNode* dfs(vector<int> nums)
    {
        if(!nums.size())
        {
            return NULL;
        }

        int split = upper_bound(nums.begin(), nums.end(), nums[0]) - nums.begin();

        vector<int> nums_l (nums.begin() + 1 , nums.begin() + split);
        vector<int> nums_r (nums.begin() + split , nums.end());

        TreeNode* node = new TreeNode(nums[0]);
        
        node -> right = dfs(nums_r);
        node -> left = dfs(nums_l);

        return node;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode* root = dfs(preorder);
        
        return root;
    }
};