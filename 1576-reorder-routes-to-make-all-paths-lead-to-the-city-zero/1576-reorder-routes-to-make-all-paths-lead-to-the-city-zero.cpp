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


class Solution {
public:
    int ret = 0;

    void dfs(int node, vvi &adj, vi &vis, vvi &c)
    {
        vis[node] = 1;

        // debug(node);

        for(auto it : adj[node])
        {
            // debug(node); debug(it);
            if((find(c[it].begin(), c[it].end(), node) == c[it].end()) && !vis[it])
            {   
                // debug(it); debug(node);
                // debug(c[it]);
                ret += 1;
                // c[it].pb(node);
            }
            if(!vis[it])
            {
                dfs(it,adj,vis,c);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vvi adj(n);

        vvi adj_c(n);

        for(auto it : connections)
        {
            adj_c[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
            adj[it[0]].pb(it[1]);
        }

        // debug(adj_c);
        // debug(adj);

        vi vis(n,0);

        dfs(0,adj,vis,adj_c);

        return ret;
    }
};