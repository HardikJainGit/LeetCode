#define vi vector <int>
#define vvi vector<vector<int>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())

class Solution {
public:

    // Always pass adj by ref otherwise tle 

    bool bfs(int i,vvi &graph,vi &vis,vi &color)
    {    
        queue<int> q;
            
        q.push(i);
        vis[i] = true;
        
        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();
            for (int u : graph[v]) 
            {
                if (!vis[u]) 
                {
                    vis[u] = true;
                    q.push(u);
                }
                if(color[u] == -1)
                {
                    color[u] = !color[v];
                }
                if(color[u] != -1 && color[u] == color[v])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v = sz(graph);
        vi vis(v,0);

        vi col(v,-1);

        f(v)
        {
            if(!vis[i])
            {
                if(!bfs(i,graph,vis,col))
                {
                    col[i] = 0;
                    return false;
                }
            }
        }

        return true;
    }
};

/* DFS : 
class Solution {
public:

    bool dfs(int node , vvi &graph , vi &vis , vi &color)
    {
        vis[node] = 1;

        for(auto it : graph[node])
        {
            if(color[it] == -1)
            {
                color[it] = !color[node];
            }
            if(!vis[it])
            {
                if(!dfs(it,graph,vis,color))
                {
                    return false;
                }
            }
            if(color[it] != -1 && color[it] == color[node])
            {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v = sz(graph);
        vi vis(v,0);

        vi col(v,-1);

        f(v)
        {
            if(!vis[i])
            {
                if(!dfs(i,graph,vis,col))
                {
                    col[i] = 0;
                    return false;
                }
            }
        }

        return true;
    }
}; 
*/