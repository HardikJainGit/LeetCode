#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vi>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& adj) 
	{
        vis[node] = 1;
        for (auto it : adj[node]) 
        {
            if (!vis[it]) 
            {
                dfs(it, vis, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int t_edg = sz(connections);
        vvi adj(n);

        for(auto it : connections)
        {
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }

        int cc = 0;
        vi vis(n,0);

        f(n)
        {
            if(!vis[i])
            {
                cc += 1;
                dfs(i,vis,adj);
            }
        }
        return (t_edg >= n-1) ? (cc - 1) : -1;
    }
};