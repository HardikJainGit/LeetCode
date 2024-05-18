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
void _print() { cout << "]\n"; }
template <typename Head, typename... Tail> void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T)) cout << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cout << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif

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

class Codec {
public:

    void dfs_s(TreeNode* root , string &s)
    {
        if(!root)
        {
            s += "N ";
            return;
        }
        s += to_string(root -> val) + ' ';
        dfs_s(root -> left,s);
        dfs_s(root -> right,s);
    }
    string serialize(TreeNode* root) 
    {
        string s;
        dfs_s(root,s);
        cout << s;
        return s;
    }

    TreeNode* dfs(stringstream &s) {
            string str;
            if (!(s >> str)) 
            {
                return NULL;
            }
            // cout << str;
            if (str == "N") 
            {
                return NULL;
            }
            TreeNode* root = new TreeNode(stoi(str));
            root->left = dfs(s);
            root->right = dfs(s);
            return root;
        }

        TreeNode* deserialize(string data) 
        {
            stringstream s(data);
            return dfs(s);
        }
    };
