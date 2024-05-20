class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
        if(!arr.size())
        {
            return false;
        }

        vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1,false));
        
        for(int i=0;i<arr.size();i++)
        {
            dp[i][0] = true;
        }
        
        if(arr[0]<=sum)
        {
            dp[0][arr[0]] = true;
        }
        
        for(int i=1;i<arr.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=arr[i])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[arr.size()-1][sum];
    }

    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum%2)
        {
            return false;
        }
        else
        {
            return isSubsetSum(nums,sum/2);
        }
    }
};