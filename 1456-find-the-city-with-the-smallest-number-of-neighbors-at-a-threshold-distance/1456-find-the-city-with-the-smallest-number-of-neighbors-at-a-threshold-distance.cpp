#define vi vector <int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vi>>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())

class Solution {
public:
#define INF 99999
    void dijkstra(int s, vector<int>& d, vvvi &adj) 
    {
        int n = d.size();
        d.assign(n, INT_MAX);
        vector<bool> vis(n, false);

        d[s] = 0;
        
        set<pair<int, int>> q;
        q.insert({0, s});
        while (!q.empty()) 
        {
            int v = (*q.begin()).second;
            q.erase(q.begin());

            for (int j = 0; j < adj[v].size(); j++) 
            {
                int to = adj[v][j][0];
                int len = adj[v][j][1];
                if (d[v] + len < d[to]) 
                {
                    d[to] = d[v] + len;
                    q.insert({d[to], to});
                    // p[to] = v;
                }
            }
        }
    }
    void floyd(vector<vector<int>>& matrix) 
    {
        int V = matrix.size();
        for (int i = 0; i < V; ++i) 
        {
            for (int j = 0; j < V; ++j) 
            {
                if (i == j) 
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int k = 0; k < V; ++k) 
        {
            for (int i = 0; i < V; ++i) 
            {
                for (int j = 0; j < V; ++j) 
                {
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j]) 
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vvi d(n,vi(n,1e9));
        vvvi adj(n);
        unordered_map<int,int> m;

        for(auto it : edges)
        {
            adj[it[0]].pb({it[1],it[2]});
            adj[it[1]].pb({it[0],it[2]});
        }

        // floyd(d);

        f(n)
        {
            dijkstra(i,d[i],adj);
        }

        // debug(d);

        f(n)
        {
            for(auto it : d[i])
            {
                if(it <= distanceThreshold && it != -1)
                {
                    m[i] += 1;
                }
            }
        }

        int mi = INT_MAX;
        int ret = INT_MIN;

        // debug(m);

        for(auto it : m)
        {
            if(it.ss < mi && it.ss <= distanceThreshold)
            {
                mi = it.ss;
                ret = it.ff;
            }
            else if(it.ss == mi)
            {
                ret = max(ret, it.ff);
            }
        }

        return ret;

    }
};
