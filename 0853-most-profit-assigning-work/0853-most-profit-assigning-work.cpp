#include <bits/stdc++.h>
using namespace std;

void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename A> void __print(const A &x);
template <typename A, typename B> void __print(const pair<A, B> &p);
template <typename... A> void __print(const tuple<A...> &t);
template <typename T> void __print(stack<T> s);
template <typename T> void __print(queue<T> q);
template <typename T, typename... U> void __print(priority_queue<T, U...> q);
template <typename A> void __print(const A &x) {
    bool first = true;
    cout << '{';
    for (const auto &i : x) {
        cout << (first ? "" : ","), __print(i);
        first = false;
    }
    cout << '}';
}
template <typename A, typename B> void __print(const pair<A, B> &p) {
    cout << '(';
    __print(p.first);
    cout << ',';
    __print(p.second);
    cout << ')';
}
template <typename... A> void __print(const tuple<A...> &t) {
    bool first = true;
    cout << '(';
    apply([&first](const auto &...args) { ((cout << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cout << ')';
}
template <typename T> void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T> void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U> void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cout << "]"<<endl; }
template <typename Head, typename... Tail> void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T)) cout << ", ";
    _print(T...);
}
#define debug(...) cout << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)

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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        vi work(sz(worker),0);
        int n = sz(worker);

        if (difficulty.empty() || profit.empty() || worker.empty())
        {
            return 0;
        }

        // srt(difficulty);
        vp fk;
        f(sz(difficulty))
        {
            fk.pb({difficulty[i],profit[i]});
        }
        srt(fk);
        srt(worker);
        // rev(fk);
        debug(fk);
        int ret = 0;
        int idx = 0;
        int m_profit = 0;

       f(n)
        {
                // // first element that is greater than worker[i]
                // auto it = upper_bound(difficulty.begin(), difficulty.end(), worker[i]);

                // if (it != difficulty.begin()) 
                // {
                //     work[i] = difficulty[it - difficulty.begin() - 1];
                //     // ret += profit[it - difficulty.begin() - 1];

                // }

                // int idx = 0;
                // int m_profit = 0;

                // Why am I doing all this in the first place ; this is too hard
                // Not made to do this ; forced af to do this

                while(idx<sz(difficulty) && worker[i] >= fk[idx].ff)
                {
                    m_profit = max(m_profit , fk[idx].ss);
                    idx += 1;
                }

                ret += m_profit;
        }

        // debug(work);

        return ret;
    }
};