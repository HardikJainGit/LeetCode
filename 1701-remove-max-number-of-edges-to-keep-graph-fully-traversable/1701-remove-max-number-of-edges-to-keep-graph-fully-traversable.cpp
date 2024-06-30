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
// #define in(x) int x; cin>>x;
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; fz(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())

struct DSU
{
    int n;
    vi p;
    DSU(int n)
    {
        p.assign(n + 1,0);
        fz(i,1,n+1)
            p[i] = i;
    }
    int par(int i)
    {
        if (p[i] == i)
            return i;
        return p[i] = par(p[i]);
    }
    bool un(int u,int v)
    {
        u = par(u),v = par(v);
        if(u==v) return false;
        p[v] = u;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        DSU alice(n);
        DSU bob(n);
        int cc = 0;
        for(auto it : edges)
        {
            if(it[0] == 3)
            {
                if(alice.un(it[1],it[2]))
                {
                    bob.un(it[1],it[2]);
                    cc += 1;
                }
            }
        }
        for(auto it : edges)
        {
            if(it[0] == 1)
            {
                if(alice.un(it[1],it[2]))
                cc += 1;
            }
            if(it[0] == 2)
            {
                if(bob.un(it[1],it[2]))
                cc += 1;
            }
        }

        int a_par = alice.par(1);
        int b_par = bob.par(1);

        fz(i,1,n+1)
        {
            // cout << alice.par(i);
            // debug(alice.par(i));
            if(alice.par(i) != a_par || bob.par(i) != b_par)
            {
                return -1;
            }
        }
        

        return sz(edges) - cc;
    }
};