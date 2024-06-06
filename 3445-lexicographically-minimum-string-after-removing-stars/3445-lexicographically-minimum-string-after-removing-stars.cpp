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
    struct Compare 
    {
        bool operator()(pair<char, int>& a, pair<char, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        }
    };

    string clearStars(string s) 
    {
    
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> q;

        int n = sz(s);

        f(n)
        {
            if(s[i] == '*')
            {
                auto it = q.top();
                // debug(it);
                q.pop();
                s[i] = '}';
                s[it.ss] = '}';
            }
            q.push({s[i],i});
        }
        s.erase(remove(s.begin(), s.end(), '}'), s.end());
        return s;
    }
};