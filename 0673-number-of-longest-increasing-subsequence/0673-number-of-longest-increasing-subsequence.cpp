class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(!nums.size())
        {
            return 0;
        }

        // dp[i] is LIS that ends at ith index

        vector <int> dp (nums.size() , 1);
        vector <int> count (nums.size() , 1);

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    if (dp[i] < dp[j] + 1) 
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // Reset count[i] because we found a longer LIS
                    }
                    else if (dp[i] == dp[j] + 1) 
                    {
                        count[i] += count[j]; // Increment count[i] because we found another LIS of the same length
                    }
                }
            }
        }

        int oc = *max_element(dp.begin() , dp.end());
        int c = 0;

        for(int i=0;i<dp.size();i++)
        {
            if(dp[i] == oc)
            {
                c += count[i];
            }
        }

        return c;

    
    }
};