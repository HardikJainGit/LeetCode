class Solution {
public:
    
    // https://www.youtube.com/watch?v=cjWnW0hdF1Y

    int lengthOfLIS(vector<int>& nums) 
    {
        if(!nums.size())
        {
            return 0;
        }

        // dp[i] is LIS that ends at ith index

        vector <int> dp (nums.size() , 1);

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin() , dp.end());

    }
};
