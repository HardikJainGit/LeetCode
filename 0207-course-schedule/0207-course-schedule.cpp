#define vi vector <int>
#define vvi vector<vector<int>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define inp(a,n) int a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; fz(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;

bool isCyclicDFS(vvi adj, vector<int> &vis, vector<int> &vis_dfs, int Node) 
{
    vis[Node] = 1;
    vis_dfs[Node] = 1;

    for(int x : adj[Node]) 
    {
        if(!vis[x]) 
        {
            bool ans = isCyclicDFS(adj, vis, vis_dfs, x);

            if(ans) 
            {
                return true;
            }
        } 
        else if(vis_dfs[x]) 
        {
            return true; //vis true and dfs vis also true
        }
    }

    vis_dfs[Node] = 0; //while returning back mark dfs vis false
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vvi adj(numCourses);
        int v = numCourses;
        
        f(sz(prerequisites))
        {
            adj[prerequisites[i][0]].pb(prerequisites[i][1]);
        }

        vi vis(v,0);
        vi dfs_v(v,0);

        for(int i=0; i<v; i++) 
        {
            if(!vis[i]) 
            {
                int ans = isCyclicDFS(adj, vis, dfs_v, i);

                if(ans) 
                {
                    return false;
                }
            }
        }
        return true;
    }
};
