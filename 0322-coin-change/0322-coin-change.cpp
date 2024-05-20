class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        // https://www.youtube.com/watch?v=H9bfqozjoqs
        // dp[i] is min coins to get sum = i

        vector<int> dp(amount + 1,INT_MAX - 1); // or initialise with amount + 1
        dp[0] = 0;

        for(int a=1;a<amount+1;a++)
        {
            for(int i=0;i<coins.size();i++)
            {
                if(a>=coins[i])
                dp[a] = min(1 + dp[a-coins[i]] , dp[a]);
            }
        }
            
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};