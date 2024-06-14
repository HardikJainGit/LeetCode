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
    int minIncrementForUnique(vector<int>& nums) 
    {
        srt(nums);
        int cc = 0;

        // unordered_map <int,int> m;

        // f(sz(nums))
        // {
        //     m[nums[i]] += 1;
        // }

        fz(i,1,sz(nums))
        {
            // debug(nums[i]);
            // debug(nums[i-1]);
            // debug(i);
            // debug(nums);
            // debug(m);
            // if(m[nums[i]] > 1)
            // {
                // debug(nums[i]);
                // debug(nums[i-1]);
                // debug(cc);
                // debug(nums);
                // m[nums[i]] -= 1;
            while(nums[i] <= nums[i-1])
            {
                cc += 1;
                nums[i] += 1;
            }
                // m[1 + nums[i-1]] += 1;
            // }
        }
        return cc;
    }
};