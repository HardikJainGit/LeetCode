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

    bool isSubsetSum_r(vector<int>arr,int no , int sum)
    {
        if(!arr.size())
        {
            return false;
        }

        if(no<0)
        {
            return false;
        }

        if(sum == 0)
        {
            return true;
        }

        if(sum>=arr[no])
        {
            return isSubsetSum_r(arr,no-1,sum) || isSubsetSum_r(arr,no-1,sum-arr[no]);
        }
        else
        {
            return isSubsetSum_r(arr,no-1,sum);
        }
    }

    bool isSubsetSum_r_memo(vector<int>arr,int no , int sum)
    {
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));

        if(sum == 0)
        {
            return true;
        }
        
        if(no<0 || sum<0)
        {
            return false;
        }

        if(dp[no][sum] != -1)
        {
            return dp[no][sum];
        }

        if(sum == 0)
        {
            return true;
        }

        if(sum>=arr[no])
        {
            return dp[no][sum] = isSubsetSum_r_memo(arr,no-1,sum) || isSubsetSum_r_memo(arr,no-1,sum-arr[no]);
        }
        else
        {
            return dp[no][sum] = isSubsetSum_r_memo(arr,no-1,sum);
        }
    }

    bool isSubsetSum_space_opt(vector<int>arr, int sum)
    {
        if(!arr.size())
        {
            return false;
        }

        // vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1,false));

        vector<bool> cur(sum + 1);
        vector<bool> next(sum + 1);

        // for(int i=0;i<arr.size();i++)
        // {
        //     dp[i][0] = true;
        // }

        cur[0] = true;
        next[0] = true;
        
        // if(arr[0]<=sum)
        // {
        //     dp[0][arr[0]] = true;
        // }

        if(arr[0]<=sum)
        {
            cur[arr[0]] = true;
        }
        
        for(int i=1;i<arr.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=arr[i])
                // dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
                next[j] = cur[j] || cur[j-arr[i]];
                else
                // dp[i][j] = dp[i-1][j];
                next[j] = cur[j];
            }
            cur = next;
        }
        
        return next[sum];
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
            return isSubsetSum_space_opt(nums,sum/2);
        }
    }
};
