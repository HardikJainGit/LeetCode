class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) 
    {
        vector <int> dp(energy.size(),0);
        dp[0] = energy[0];
        int mx = INT_MIN;
        
        for(int i=energy.size() - 1;i>=0;i--)
        {
            if(i+k<energy.size()) 
            {
                dp[i] = dp[i+k] + energy[i];
            }
            else
            {
                dp[i] = energy[i];
            }
            if(dp[i] > mx)
            {
                mx = dp[i];
            }
        }
        return mx;
    }
};