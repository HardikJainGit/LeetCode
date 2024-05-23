#define vi vector <int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())

// class Solution {
// public:
//     bool dfs(int mid, vvi &heights, int i, int j, vvi &vis) 
//     {
//         int m = sz(heights);
//         int n = sz(heights[0]);

//         if (i == m - 1 && j == n - 1) 
//         {
//             return true;
//         }

//         if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j]) 
//         {
//             return false;
//         }

//         vis[i][j] = 1;

//         int drow[] = {-1, 1, 0, 0};
//         int dcol[] = {0, 0, -1, 1};

//         fz(k, 0, 4) 
//         {
//             int nrow = i + drow[k];
//             int ncol = j + dcol[k];

//             if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]) 
//             {
//                 if (abs(heights[nrow][ncol] - heights[i][j]) <= mid) 
//                 {
//                     if (dfs(mid, heights, nrow, ncol, vis)) 
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }

//     int minimumEffortPath(vector<vector<int>>& heights) 
//     {
//         int m = sz(heights);
//         int n = sz(heights[0]);

//         if(!m && !n)
//         {
//             return 0;
//         }

//         int lo = -1;
//         int hi = 1e6 + 1;
//         int mid = 0;
        
//         while (hi - lo > 1)
//         {
//             vvi vis(m,vi(n,0));
//             mid = (hi + lo) / 2;
    
//             if (dfs(mid,heights,0,0,vis)) // FFFFTTTT
//             {
//                 hi = mid;
//             }
//             else
//             {
//                 lo = mid;
//             }
//         }

//         return hi;
//     }   
// };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();
        
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

            f(4)
            {
                int nrow = row + delrow[i]; 
                int ncol = col + delcol[i]; 
                    
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) 
                {
                    int mx = max(ef, abs(heights[nrow][ncol] - heights[row][col]));
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
