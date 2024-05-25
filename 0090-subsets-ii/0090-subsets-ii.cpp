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

        while(i + 1 < n && nums[i] == nums[i+1])
        {
            i += 1;
        }
        
        dfs(i + 1 , subz , nums , n , ret);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());  
        vector<int> subz;
        dfs(0, subz, nums, nums.size(), ret);
        return ret;
    }
};
