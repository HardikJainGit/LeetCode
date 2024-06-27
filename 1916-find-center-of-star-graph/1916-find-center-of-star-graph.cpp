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
    int findCenter(vector<vector<int>>& edges) 
    {
        // unordered_map<int,int> m;
        int rep = -1;
        int x = -1;
        int y = -1;
        int f = 0;
        for(auto it : edges)
        {
            if(it[0] == x || it[1] == x)
            {
                return x;
            }

            if(it[0] == y || it[1] == y)
            {
                return y;
            }
            
            if(!f)
            {
                x = it[0]; y = it[1];
                f = 1;
            }

            // m[it[1]] += 1;
            // m[it[0]] += 1;
        }
        // for(auto it : m)
        // {
        //     if(it.ss > 1)
        //     {
        //         return it.ff;
        //     }
        // }
        return -1;
    }
};