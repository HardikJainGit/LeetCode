#define vi vector <int>
#define vvi vector<vector<int>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())

class Solution {
public:

    void dfs(int nr , int nc ,vector<vector<char>> &grid , vvi &vis)
    {
        int r = sz(grid);
        int c = sz(grid[0]);

        if (nr < 0 || nc < 0 || nr >= r || nc >= c || vis[nr][nc] || grid[nr][nc] == '0')
        {
            return;
        }

        vis[nr][nc] = 1;

        int i = nr; int j = nc;

        dfs(i+1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j-1,grid,vis);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
        {
            return 0;
        }

        int r = sz(grid);
        int c = sz(grid[0]);

        int isl = 0;
        vvi vis(r,vi(c,0));

        f(r)
        {
            fz(j,0,c)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    isl += 1;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return isl;
    }
};