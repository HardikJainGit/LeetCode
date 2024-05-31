#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vi>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int n = sz(piles);

        vector<vp> dp(sz(piles) , vp(sz(piles),{0,0}));

        f(n)
        {
            fz(j,0,n)
            {
                if(i == j)
                {
                    dp[i][j].ff = piles[i];
                    dp[i][j].ss = 0;
                }
            }
        }

        f(n-1)
        {
            fz(j,1,n)
            {
                dp[i][j].ff = max(piles[i] + dp[i+1][j].ss , piles[j] + dp[i][j-1].ss);
                if(piles[i] + dp[i+1][j].ss > piles[j] + dp[i][j-1].ss)
                {
                    dp[i][j].ss = dp[i+1][j].ff;
                }
                else
                {
                    dp[i][j].ff = dp[i][j-1].ff;
                }
             }
        }

        return dp[0][n-1].ff > dp[0][n-1].ss;
    }
};
