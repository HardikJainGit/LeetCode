class Solution {
public:
    TreeNode* dfs(vector<int> nums)
    {
        if(!nums.size())
        {
            return NULL;
        }

        vector<int> nums_l (nums.begin() , nums.begin() + (nums.size()/2));
        vector<int> nums_r (nums.begin() + (nums.size()/2) + 1 , nums.end());

        TreeNode* node = new TreeNode(nums[nums.size()/2]);
        
        node -> right = dfs(nums_r);
        node -> left = dfs(nums_l);

        return node;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n = nums.size();
        TreeNode* root = dfs(nums);
        
        return root;
    }
};