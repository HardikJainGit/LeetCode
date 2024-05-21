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

class Solution {
public:
    void Kahn(int i , vector<int> &topo, vvi adj, vector<int> &indegree, vector<int> &vis) 
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
            
            topo.push_back(v);
            
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
    
	vector<int> topoSort(int V, vvi adj) 
	{
	    int v = V;
	    vector<int> indegree(v,0);
        vector<int> vis(v,0);
        vector<int> topo;
    
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vvi adj(numCourses);
        f(sz(prerequisites))
        {
            adj[prerequisites[i][1]].pb(prerequisites[i][0]);
        }

        vector<int> topo = topoSort(numCourses, adj);
        
        return sz(topo) == numCourses;
    }
};