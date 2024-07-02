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
    bool fit(string a,string b)
    {
        int f = 0;
        f(sz(a))
        {
            if(a[i] != b[i])
            {
                if(!f)f = 1;
                else return false;
            }
        }
        return true;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_map <string,vector<string>> adj;

        if(startGene == endGene)
        {
            return 0;
        }

        if(find(bank.begin(),bank.end(),endGene) == bank.end())
        {
            return -1;
        }

        f(sz(bank))
        {
            if(fit(startGene,bank[i]))
            {
                adj[bank[i]].pb(startGene);
                adj[startGene].pb(bank[i]);
            }
            fz(j,i+1,sz(bank))
            {
                if(fit(bank[i],bank[j]))
                {
                    adj[bank[i]].pb(bank[j]);
                    adj[bank[j]].pb(bank[i]);
                }
            }
        }

        // debug(adj);
        unordered_map<string,int> vis(sz(bank)+1);
        unordered_map<string,int> d(sz(bank)+1);
        d[startGene] = 0;
        // vis [startGene] = 1;
        // int n = N; // number of nodes
        // int s = src; // source vertex
        
        queue<string> q;
        
        q.push(startGene);
        vis[startGene] = 1;

        while (!q.empty()) 
        {
            string v = q.front();
            q.pop();
            for (auto u : adj[v]) 
            {
                if (!vis[u]) 
                {
                    vis[u] = 1;
                    q.push(u);
                    d[u] = d[v] + 1;
                }
            }
        }
        return (d[endGene] ? d[endGene] : -1);
    }
};