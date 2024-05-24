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
    
};