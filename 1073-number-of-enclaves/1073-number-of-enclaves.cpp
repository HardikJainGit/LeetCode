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
    void floodFill(vector<vector<int>>& image, int i, int j)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] != 1)
        {
            return;
        }

        image[i][j] = 0;
        
        floodFill(image,i-1,j);
        floodFill(image,i+1,j);
        floodFill(image,i,j-1);
        floodFill(image,i,j+1);
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int r = sz(grid);
        int c = sz(grid[0]);

        f(r)
        {
            if(grid[i][0] == 1)
            {
                floodFill(grid,i,0);
            }
            if(grid[i][c-1] == 1)
            {
                floodFill(grid,i,c-1);
            }
        }
        f(c)
        {
            if(grid[0][i] == 1)
            {
                floodFill(grid,0,i);
            }
            if(grid[r-1][i] == 1)
            {
                floodFill(grid,r-1,i);
            }
        }
        int eclv = 0;
        f(r)
        {
            fz(j,0,c)
            {
                if(grid[i][j] == 1)
                {
                    eclv += 1;
                }
            }
        }

        return eclv;
    }
};