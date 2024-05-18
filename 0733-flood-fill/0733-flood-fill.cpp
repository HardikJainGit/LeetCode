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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size(); //n*m
	    int m = image[0].size(); 

	    vvi vis(n, vi(m, 0)); 
	    vvi dist(n, vi(m, 0)); 

	    queue<pi> q; 
        q.push({sr,sc});

        int o_col = image[sr][sc];
        image[sr][sc] = color;
        
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    while(!q.empty()) 
        {
	        int size = sz(q);

            int row = q.front().ff;
            int col = q.front().ss; 
            q.pop();

            f(4)
            {
                int nrow = row + delrow[i]; 
                int ncol = col + delcol[i]; 
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == o_col) 
                {
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1; 
                    q.push({nrow, ncol});  
                }
            }
	    }
        return image;
    }
};