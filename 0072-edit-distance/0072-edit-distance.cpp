#define vi vector <int>
#define vvi vector<vector<int>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)


class Solution {
public:
    
    // https://www.youtube.com/watch?v=XYi2-LPrwm4

    int minDistance(string word1, string word2) 
    {
        vvi dp(word2.length() + 1 , vi(word1.length() + 1, 0));

        int n2 = word2.length();
        int n1 = word1.length();

        f(n2+1)
        {
            fz(j,0,n1+1)
            {
                if(j == n1)
                {
                    dp[i][j] = n2 - i;
                }
                if(i == n2)
                {
                    dp[i][j] = n1 - j;
                }
            }
        }

        for(int i=n2-1;i>=0;i--)
        {
            for(int j=n1-1;j>=0;j--)
            {
                if(word2[i] == word1[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else 
                {
                    dp[i][j] = 1 + min({dp[i][j+1] , dp[i+1][j] , dp[i+1][j+1]});
                }
            }
        }

        // Debug :

        for (const auto& row : dp) 
        {
            for (const auto& element : row) 
            {
                cout << element << " ";
            }
            cout << endl;
        }

        return dp[0][0];
    }
};
