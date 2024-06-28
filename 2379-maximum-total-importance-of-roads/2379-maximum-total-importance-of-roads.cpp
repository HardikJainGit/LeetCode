#define py cout << "YES\n";
#define pn cout << "NO\n";
#define vi vector <int>
#define vvi vector<vector<int>>
#define vp vector<pair<long long,long long>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
// #define in(x) int x; cin>>x;
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; fz(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())


class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vp in(n);
        for(auto it : roads)
        {
            in[it[0]].ff += 1;
            in[it[0]].ss = it[0];
            in[it[1]].ss = it[1];
            in[it[1]].ff += 1;
        }

        srt(in);
        // sort(in.begin(), in.end(), [](const pi &a, const pi &b) {
        //     return a.ff > b.ff;
        // });
        long long ret = 0;
        // debug(in);
        int i = 1;

        for(auto it : in)
        {
            ret += it.ff * (i);
            i += 1;
        }

        return ret;
        // srt(in);
    }
};