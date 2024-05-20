class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // https://www.youtube.com/watch?v=Sx9NNgInc3A

        // dp[i] is whether word starting from index i is found in wordDict

        vector<int> dp(s.length() + 1 , 0);
        dp[s.length()] = 1;

        for(int i=s.length();i>=0;i--)
        {
            for(auto it : wordDict)
            {
                if(it.length() + i <= s.length() + 1 && s.substr(i,it.length()) == it)
                {
                    dp[i] =dp[i+it.length()];
                }
                if(dp[i]) // one word is sufficient
                {
                    break;
                }
            }
        }

        return dp[0];
    }
};