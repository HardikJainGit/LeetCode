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

struct DSU
{
    int n;
    vi p;
    DSU(int n)
    {
        p.assign(n + 1,0);
        fz(i,1,n+1)
            p[i] = i;
    }
    int par(int i)
    {
        if (p[i] == i)
            return i;
        return p[i] = par(p[i]);
    }
    void un(int u,int v)
    {
        u = par(u),v = par(v);
        if(u==v) return;
        p[v] = u;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
        {
            return 0;
        }

        int r = sz(grid);
        int c = sz(grid[0]);
        vi vis(r * c + 1,0);

        DSU dsu(r * c);
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        f(r) 
        {
            fz(j, 0, c) 
            {
                if (grid[i][j] == '1') 
                {
                    fz(k, 0, 4) 
                    {
                        int nr = i + delRow[k], nc = j + delCol[k];
                        if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == '1') 
                        {
                            dsu.un(i * c + j, nr * c + nc);
                        }
                    }
                }
            }
            
        }

        int isl = 0;

        unordered_set<int> uniqueIslands;

        // Use set if don't want to be bothered by unifying zeroes

        fz(i, 0, r) 
        {
            fz(j, 0, c) 
            {
                if (grid[i][j] == '1')
                {
                    uniqueIslands.insert(dsu.par(i * c + j));
                }
            }
        }

        return uniqueIslands.size();
    }
};
// #include <bits/stdc++.h>
// using namespace std;
// void __print(int x) { cout << x; }
// void __print(long x) { cout << x; }
// void __print(long long x) { cout << x; }
// void __print(unsigned x) { cout << x; }
// void __print(unsigned long x) { cout << x; }
// void __print(unsigned long long x) { cout << x; }
// void __print(float x) { cout << x; }
// void __print(double x) { cout << x; }
// void __print(long double x) { cout << x; }
// void __print(char x) { cout << '\'' << x << '\''; }
// void __print(const char *x) { cout << '\"' << x << '\"'; }
// void __print(const string &x) { cout << '\"' << x << '\"'; }
// void __print(bool x) { cout << (x ? "true" : "false"); }
// template <typename A> void __print(const A &x);
// template <typename A, typename B> void __print(const pair<A, B> &p);
// template <typename... A> void __print(const tuple<A...> &t);
// template <typename T> void __print(stack<T> s);
// template <typename T> void __print(queue<T> q);
// template <typename T, typename... U> void __print(priority_queue<T, U...> q);
// template <typename A> void __print(const A &x) {
//     bool first = true;
//     cout << '{';
//     for (const auto &i : x) {
//         cout << (first ? "" : ","), __print(i);
//         first = false;
//     }
//     cout << '}';
// }
// template <typename A, typename B> void __print(const pair<A, B> &p) {
//     cout << '(';
//     __print(p.first);
//     cout << ',';
//     __print(p.second);
//     cout << ')';
// }
// template <typename... A> void __print(const tuple<A...> &t) {
//     bool first = true;
//     cout << '(';
//     apply([&first](const auto &...args) { ((cout << (first ? "" : ","), __print(args), first = false), ...); }, t);
//     cout << ')';
// }
// template <typename T> void __print(stack<T> s) {
//     vector<T> debugVector;
//     while (!s.empty()) {
//         T t = s.top();
//         debugVector.push_back(t);
//         s.pop();
//     }
//     reverse(debugVector.begin(), debugVector.end());
//     __print(debugVector);
// }
// template <typename T> void __print(queue<T> q) {
//     vector<T> debugVector;
//     while (!q.empty()) {
//         T t = q.front();
//         debugVector.push_back(t);
//         q.pop();
//     }
//     __print(debugVector);
// }
// template <typename T, typename... U> void __print(priority_queue<T, U...> q) {
//     vector<T> debugVector;
//     while (!q.empty()) {
//         T t = q.top();
//         debugVector.push_back(t);
//         q.pop();
//     }
//     __print(debugVector);
// }
// void _print() { cout << "]\n"; }
// template <typename Head, typename... Tail> void _print(const Head &H, const Tail &...T) {
//     __print(H);
//     if (sizeof...(T)) cout << ", ";
//     _print(T...);
// }
// #ifndef ONLINE_JUDGE
// #define debug(...) cout << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
// #else
// #define debug(...)
// #endif

// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vvvi vector<vector<vi>>
// #define f(b) for(int i=0;i<b;i++)
// #define fz(i,a,b) for(int i=a;i<b;i++)
// #define sz(x) ((int)(x).size())
// #define vp vector<pair<int,int>>
// #define pi pair<int,int>
// #define pb push_back
// #define ff first
// #define ss second

// struct DSU
// {
//     int n;
//     vi p;
//     DSU(int n)
//     {
//         p.assign(n + 1,0);
//         fz(i,1,n+1)
//             p[i] = i;
//     }
//     int par(int i)
//     {
//         if (p[i] == i)
//             return i;
//         return p[i] = par(p[i]);
//     }
//     void un(int u,int v)
//     {
//         u = par(u),v = par(v);
//         if(u==v) return;
//         p[v] = u;
//     }
// };

// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) 
//     {
//         if(grid.empty())
//         {
//             return 0;
//         }

//         int r = sz(grid);
//         int c = sz(grid[0]);
//         DSU dsu(r * c);
//         int delRow[] = {-1, 0, 1, 0};
//         int delCol[] = {0, 1, 0, -1};
//         int f = 0;
//         int fzr;
//         int fzc;
//         int zf = 0;

//         f(r) 
//         {
//             fz(j, 0, c) 
//             {
//                 if (grid[i][j] == '1') 
//                 {
//                     fz(k, 0, 4) 
//                     {
//                         int nr = i + delRow[k], nc = j + delCol[k];
//                         if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == '1') 
//                         {
//                             dsu.un(i * c + j, nr * c + nc);
//                         }
//                     }
//                 }
//                 else
//                 {
//                     zf = 1;
//                     if(!f)
//                     {
//                         fzr = i; 
//                         fzc = j;
//                         f = 1;
//                     }

//                     else
//                     dsu.un(i*c+j,fzr*c+fzc);
//                 }
//             }
//         }

//         vi vis(r * c + 1,0);
//         int isl = 0;

//         fz(i, 0, r) 
//         {
//             fz(j, 0, c) 
//             {
//                 int p = dsu.par(i * c + j);
//                 debug(p);
//                 debug(vis[p]);
//                 if (!vis[p]) 
//                 {
//                     isl += 1;
//                     vis[p] = 1;
//                 }
//             }
//         }

//         return zf ? isl - 1 : isl;
//     }
// };
