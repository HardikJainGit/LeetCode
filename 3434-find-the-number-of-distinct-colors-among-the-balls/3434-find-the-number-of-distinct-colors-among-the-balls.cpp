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

/* Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

Output: [1,2,2,3] */

class Solution {
public:
    // int distinct(vvi &queries , int &limit ,vi &ball_to_color)
    // {
    //     set <int> s;
    //     debug(ball_to_color);
    //     for(auto it : ball_to_color)
    //     {
    //         if(it!=0)
    //         s.insert(it);
    //     }
    //     return s.size();
    // }
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        unordered_map <int,int> ball_to_color;
        vi r;
        unordered_map <int,int> color_to_f;

        for(auto it : queries)
        {
            if(ball_to_color.find(it[0]) != ball_to_color.end())
            {
                color_to_f[ball_to_color[it[0]]] -= 1;
                
                if(color_to_f[ball_to_color[it[0]]] == 0)
                {
                    color_to_f.erase(ball_to_color[it[0]]);
                }
            }

            ball_to_color[it[0]] = it[1];
            color_to_f[it[1]] += 1;

            // m[it[1]] += 1;
            // int ret = distinct(queries,limit,ball_to_color);

            int ret = sz(color_to_f);
            r.pb(ret);
        }

        return r;
    }
};