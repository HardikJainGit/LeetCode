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
#define inp(a,n) int a[n]; f(n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = sz(matrix);
        int n = sz(matrix[0]);
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if the first row has any zeros
        f(n) 
        {
            if(matrix[0][i] == 0) 
            {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column has any zeros
        f(m) 
        {
            if(matrix[i][0] == 0) 
            {
                firstColZero = true;
                break;
            }
        }

        // Use the first row and column to mark zeros
        fz(i, 1, m) 
        {
            fz(j, 1, n) 
            {
                if(matrix[i][j] == 0) 
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero out cells based on the first row and column markers
        fz(i, 1, m) 
        {
            fz(j, 1, n) 
            {
                if((matrix[i][0] == 0 || matrix[0][j] == 0) && matrix[i][j] ) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if(firstRowZero) 
        {
            f(n) 
            {
                matrix[0][i] = 0;
            }
        }

        // Zero out the first column if needed
        if(firstColZero) 
        {
            f(m) 
            {
                matrix[i][0] = 0;
            }
        }
    }
};
