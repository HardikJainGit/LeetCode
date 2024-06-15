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
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = sz(profits);
        vp q(n);

        f(sz(profits))
        {
            q[i].ss = profits[i];
            q[i].ff = capital[i];
        }
        // debug(q);

        srt(q); // sort on the basis of capital
        // rev(q);
        // debug(q);
        priority_queue<int> pq;
        int i = 0;

        // debug(*lower_bound(all(capital),1));

        while(k--)
        {
            // vector<pi> q_buf;
            // q_buf = q;
            
            // w += *l;
            // while(!q_buf.empty())
            // for(auto it : q)
            // {
                // auto l = upper_bound(all(capital),w);

                // if(l == capital.end())
                // {
                //     *l = INT_MAX;
                // }

                // debug(*l);
                // debug(w);

                // since q is vp find which index is greater than w ; search before it
                int l = upper_bound(q.begin()+l, q.end(), make_pair(w, INT_MAX))-q.begin();

                while (i < l && q[i].ff <= w) 
                {
                    pq.push(q[i].ss);
                    i++;
                }

                if(pq.empty())
                {
                    break;
                }

                w += pq.top();
                pq.pop();
                // break;
                
                // if(l == capital.end())
                // {
                //     *l = maxv(capital);
                // }

                // if(it.ss != *l)
                // {
                //     continue;
                // }
                // else
                // {
                //     w += it.ff;
                //     break;
                // }

                // debug(*l);
                // debug(w);
                // debug(q_buf.top());
                // if(q_buf.top().ss != *l)
                // {
                //     q_buf.pop();
                // }
                // else
                // {
                //     w += q_buf.top().ff;
                //     // q_buf.pop();
                //     break;
                // }
            // }
            // q.pop();
        }
        return w;
    }
};