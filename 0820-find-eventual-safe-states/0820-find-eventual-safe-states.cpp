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

// Always pass adj by ref to avoid TLE

class Solution {
public:
    void Kahn(int i , set<int> &topo, vvi &adj, vector<int> &indegree, vector<int> &vis) 
    {
        queue<int> q;

        if(indegree[i] == 0 && !vis[i])
        {
            q.push(i);
            vis[i] = 1;
        }
    
        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();
            
            topo.insert(v);
            
            for (int u : adj[v]) 
            {
                indegree[u]--;
                
                if (!vis[u] && !indegree[u]) 
                {
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    
	set<int> topoSort(int V, vvi &adj) 
	{
	    int v = V;
	    vector<int> indegree(v,0);
        vector<int> vis(v,0);
        set<int> topo;
    
        for (int i = 0; i < V; ++i)
        {
            for (int el : adj[i])
            {
                indegree[el]++;
            }
        }

        for(int i=0; i<v; i++) 
        {
            if(!vis[i] && indegree[i] == 0) 
            {
                Kahn(i,topo, adj, indegree, vis);
            }
        }
    
        return topo;
	}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vvi graph_T(sz(graph));
        for(int i=0;i<sz(graph);i++)
        {
            for(auto it : graph[i])
            {
                graph_T[it].push_back(i);
            }
        }
        set<int> ret = topoSort(sz(graph),graph_T);
        vi v;
        for(auto it: ret)
        {
            v.push_back(it);
        }
        return v;
    }
};