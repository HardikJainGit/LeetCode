
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
    void dfs(unordered_map <string,unordered_map<string,double>> &m, string b, unordered_map <string,int> &vis, string node, double &cur, double &ret)
    {
        vis[node] = 1;

        if(node == b)
        {
            ret = cur;
            return;
        }
        
        for(auto it : m[node])
        {
            if(!vis[it.ff])
            {
                // debug(cur);
                // debug(it.ss);
                // debug(it.ff);
                cur *= it.ss;
                dfs(m,b,vis,it.ff,cur,ret);
                cur /= it.ss; // backtrack
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map <string,unordered_map<string,double>> m;
        int i = 0;

        for(auto it : equations)
        {
            m[it[0]][it[1]] = double(values[i]);
            // double val = double(values[i]);
            m[it[1]][it[0]] = 1.0/values[i];
            i += 1;
        } 

        vector <double> v;

        for(auto it : queries)
        {
            double ret = -1.0;
            double c = 1.0;
            
            unordered_map<string,int> vis;
                        
            if (m.find(it[0]) == m.end() || m.find(it[1]) == m.end()) 
            {
                v.push_back(-1.0); 
                continue;
            }
            if (it[0] == it[1]) 
            {
                v.push_back(1.0); 
                continue;
            }

            dfs(m,it[1],vis,it[0],c,ret);
            v.pb(ret);
        }

        return v;
    }
};