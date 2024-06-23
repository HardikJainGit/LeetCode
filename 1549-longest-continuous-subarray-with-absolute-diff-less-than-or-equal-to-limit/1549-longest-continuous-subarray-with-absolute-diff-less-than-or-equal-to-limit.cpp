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
    int longestSubarray(vector<int>& nums, int limit) 
    {
        // int r = 0;
        int l = 0;
        int n = sz(nums);
        int e = limit;

        multiset<int> s;
        // s.insert(0);

        int mx = INT_MIN;
        int mi = INT_MAX;

        int ret = 0;

        fz(r,0,n)
        {
            s.insert(nums[r]);
            mx = *s.rbegin();
            mi = *s.begin();

            // while(mx - mi <= e)
            // {
            //     r += 1;
            // }
            while(mx - mi > e)
            {
                s.erase(s.find(nums[l]));
                l += 1;
                mx = *s.rbegin();
                mi = *s.begin();
            }

            ret = max(ret , r - l + 1);
        }

        return ret;
    }
};