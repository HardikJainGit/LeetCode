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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size(); //n*m
	    int m = grid[0].size(); 

        if (n == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1) 
        {
            return -1;
        }

	    vvi vis(n, vector<int>(m, 0)); 

	    queue<pi> q; 

	    q.push({0,0});
        vis[0][0] = 1;

	    int delrow[] = {-1, -1, -1, 0, +1, +1, +1, 0};
        int delcol[] = {0, +1, -1, +1, 0, -1, +1, -1};

        int count = 0;
	    
	    while(!q.empty()) 
        {
	        int size = sz(q);

           fz(k,0,size)
           {
                int row = q.front().ff;
	            int col = q.front().ss; 
                q.pop();

                if(row == n-1 && col == m-1)
                {
                    return count + 1;
                }

                f(8) 
                {
                    int nrow = row + delrow[i]; 
                    int ncol = col + delcol[i]; 
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 0) 
                    {
                        vis[nrow][ncol] = 1; 
                        q.push({nrow, ncol});  
                    }
                }
            }
                
            count += 1;

	    }

        return -1;
    } 
};