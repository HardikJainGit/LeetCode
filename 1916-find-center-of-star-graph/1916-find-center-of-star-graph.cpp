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
        unordered_map<int,int> m;
        for(auto it : edges)
        {
            m[it[1]] += 1;
            m[it[0]] += 1;
        }
        for(auto it : m)
        {
            if(it.ss > 1)
            {
                return it.ff;
            }
        }
        return -1;
    }
};