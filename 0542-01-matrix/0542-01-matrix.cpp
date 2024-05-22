#define py cout << "YES\n";
#define pn cout << "NO\n";
#define vi vector <int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; fz(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int r = sz(mat);
        int c = sz(mat[0]);
        vvi dp(r,vi(c,INT_MAX));
        vvi vis(r,vi(c,0));
        queue <pair<int,int>> q;
        
        f(r)
        {
            fz(j,0,c)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                    dp[i][j] = 0;
                }
            }
        }
        

        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 

        int temp = 0;
	    
	    while(!q.empty()) 
        {

                int row = q.front().ff;
	            int col = q.front().ss; 
                q.pop();

                f(4) 
                {
                    int nrow = row + delrow[i]; 
                    int ncol = col + delcol[i]; 
                    
                    if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && !vis[nrow][ncol] && mat[nrow][ncol]) 
                    {
                        if (dp[nrow][ncol] > dp[row][col] + 1) 
                        {
                            dp[nrow][ncol] = dp[row][col] + 1;
                            q.push({nrow, ncol});
                        }
                    }
              }
	    }

        return dp;
    }
};