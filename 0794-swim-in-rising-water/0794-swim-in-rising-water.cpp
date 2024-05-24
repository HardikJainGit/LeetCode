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
struct DSU
{
    int n;
    vi p;
    DSU(int n)
    {
        p.assign(n + 1,0);
        fz(i,1,n+1)
            p[i] = i;
    }
    int par(int i)
    {
        if (p[i] == i)
            return i;
        return p[i] = par(p[i]);
    }
    void un(int u,int v)
    {
        u = par(u),v = par(v);
        if(u==v) return;
        p[v] = u;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        if(grid.empty())
        {
            return 0;
        }

        int r = sz(grid);
        int c = sz(grid[0]);
        set<pair<int,pi>> q;

        DSU dsu(r * c);
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        f(r) 
        {
            fz(j, 0, c) 
            {
                fz(k, 0, 4) 
                {
                    int nr = i + delRow[k], nc = j + delCol[k];
                    if (nr >= 0 && nr < r && nc >= 0 && nc < c) 
                    {
                        q.insert({max(grid[i][j] , grid[nr][nc]),{i * c + j, nr * c + nc}});
                    }
                }
            }
        }
        for (auto it : q)
        {
            int w = it.ff;
            int u = it.ss.ff;
            int v = it.ss.ss;

            dsu.un(u, v);

            if (dsu.par(0) == dsu.par((r-1)*c + c-1)) 
            {
                return w;
            }
        }
       return 0;
    }

};
/* #include <bits/stdc++.h>
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
    bool dfs(int mid, vvi &grid, int i, int j, vvi &vis) 
    {
        int m = sz(grid);
        int n = sz(grid[0]);

        if (i == m - 1 && j == n - 1) 
        {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j]) 
        {
            return false;
        }

        vis[i][j] = 1;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        fz(k, 0, 4) 
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]) 
            {
                if (max(grid[nrow][ncol], grid[i][j]) <= mid) 
                {
                    if (dfs(mid, grid, nrow, ncol, vis)) 
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) 
    {
        int m = sz(grid);
        int n = sz(grid[0]);

        if(!m && !n)
        {
            return 0;
        }

        int lo = -1;
        int hi = 1e6 + 1;
        int mid = 0;
        
        while (hi - lo > 1)
        {
            vvi vis(m,vi(n,0));
            mid = (hi + lo) / 2;
    
            if (dfs(mid,grid,0,0,vis)) // FFFFTTTT
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        return hi;
    }   
};
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vvi d(n, vi(m, INT_MAX));
        d[0][0] = 0;
        
        int delrow[] = {-1, 0, 1, 0}; 
	    int delcol[] = {0, 1, 0, -1}; 
        
        set<pair<int, pi>> q;
        q.insert({0, {0,0}});
        
        while (!q.empty()) 
        {
            int row = (*q.begin()).ss.ff;
            int col = (*q.begin()).ss.ss;
            int ef = (*q.begin()).ff;
            q.erase(q.begin());

            if(row == n-1 && col == m-1)
            {
                return d[row][col];
            }

            for (int i = 0; i < 4; i++) 
            {
                int nrow = row + delrow[i]; 
                int ncol = col + delcol[i]; 
                    
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) 
                {
                    int mx = max({ef,grid[nrow][ncol] , grid[row][col]});
                    if(mx < d[nrow][ncol]) 
                    {
                        d[nrow][ncol] = mx;
                        q.insert({mx,{nrow, ncol}});  
                    }
                }
            }
        }
        
        return -1;
    }
    
 */