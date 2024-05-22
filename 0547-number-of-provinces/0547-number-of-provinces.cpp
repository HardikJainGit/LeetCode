#define vi vector <int>
#define vvi vector<vector<int>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())

class Solution {
public:
    void dfs(int i ,vector<vector<int>> &isConnected , vi &vis)
    {   
        vis[i] = 1;

        for(int j=0;j<isConnected[i].size();j++)
        {
            if(!vis[j] && isConnected[i][j])
            {
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        if(isConnected.empty())
        {
            return 0;
        }

        int r = sz(isConnected);
        int c = sz(isConnected[0]);

        int prvc = 0;
        vi vis(r,0);

        f(r)
        {
            if(!vis[i])
            {
                prvc += 1;
                dfs(i,isConnected,vis);
            }
        }
        return prvc;
    }
};