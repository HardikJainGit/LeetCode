class Solution {
public:
    void dfs(int i, vector<int>& subz, vector<int>& nums, int n, vector<vector<int>>& ret) 
    {
        if(i == n)
        {
            ret.push_back(subz);
            return;
        }

        subz.push_back(nums[i]);
        dfs(i + 1 , subz , nums , n , ret);
        subz.pop_back();
        dfs(i + 1 , subz , nums , n , ret);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        vector<int> subz;
        dfs(0, subz, nums, nums.size(), ret);
        return ret;
    }
};