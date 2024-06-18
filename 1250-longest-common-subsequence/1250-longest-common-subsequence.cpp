class Solution {
public:

    int solve(string& a, string& b, int i, int j){

        // Base Case
        if(i == a.length())
            return 0;

        if(j == b.length())
            return 0;

        int ans = 0;

        if(a[i] == b[j])
            ans = 1 + solve(a, b, i+1, j+1);

        else
        {
            ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
        }

        return ans;
    }

    int solveMem(string& a, string& b, int i, int j, vector<vector<int>> &dp){

        // Base Case
        if(i == a.length())
            return 0;

        if(j == b.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if(a[i] == b[j])
            ans = 1 + solveMem(a, b, i+1, j+1, dp);

        else
        {
            ans = max(solveMem(a, b, i+1, j, dp), solveMem(a, b, i, j+1, dp));
        }

        return dp[i][j] = ans;
    }

    int solveTab(string& a, string& b){

        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

        for(int i = n1-1; i>=0; i--){
            for(int j = n2-1; j>=0; j--){
                int ans = 0;

                if(a[i] == b[j])
                    ans = 1 + dp[i+1][j+1];

                else
                {
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }

                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }

    int solveSpaceOP(string& a, string& b){

        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

        vector<int> currRow(n2+1, 0);
        vector<int> nextRow(n2+1, 0);

        for(int i = n1-1; i>=0; i--){
            for(int j=n2-1;j>=0;j--){
                int ans = 0;

                if(a[i] == b[j]) //due to this condition cant reverse j in this case
                    ans = 1 + nextRow[j+1];

                else
                {
                    ans = max(nextRow[j], currRow[j+1]);
                }

                currRow[j] = ans;
            }

            nextRow = currRow;
        }
        
        return nextRow[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // RECURSION
        // return solve(text1, text2, 0, 0);

        // RECURSION + MEMOIZATION
        /*
        int n1 = text1.length();
        int n2 = text2.length();
        
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));

        return solveMem(text1, text2, 0, 0, dp);
        */

        // TABULATION
        // return solveTab(text1, text2);

        // SPACE OPTIMIZATION
        return solveSpaceOP(text1, text2);
    }
};