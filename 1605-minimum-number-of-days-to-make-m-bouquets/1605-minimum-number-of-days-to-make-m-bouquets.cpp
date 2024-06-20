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
    
    bool condition (long long mid , vi &bloomDay , int m , int k)
    {
        // debug(mid);
        int cc = 0;
        // vi pos;
        int fcc = 0;

        f(sz(bloomDay))
        {
            if(bloomDay[i] <= mid)
            {
                // debug(bloomDay[i]);
                cc += 1;
                if(cc == k)
                {
                    fcc += 1;
                    cc = 0;
                }
            }
            else
            {
                cc = 0;
            }
        }

        // if(cc) pos.pb(cc);

        // debug(pos);

        // f(sz(pos))
        // {
        //     if(pos[i] >= k)
        //     {
        //         fcc += 1;
        //     }
        // }

        return (fcc >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = sz(bloomDay);
        if (1LL * m * k > n) 
        {
            return -1;
        }

        long long lo = -1;
        long long hi = maxv(bloomDay);
        long long mid = 0;
        
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
    
            if (condition(mid,bloomDay,m,k))
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