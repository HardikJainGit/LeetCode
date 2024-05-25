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
    void dfs(int i , vi& cur , vvi &ret , int &target , int tot, vi &candidates)
    {                
        if(tot == target)
        {
            ret.pb(cur);
            return;
        }

        if(i >= sz(candidates) || tot > target)
        {
            return;
        }

        cur.pb(candidates[i]);
        dfs(i,cur,ret,target,tot + candidates[i],candidates);
        cur.pop_back();

        dfs(i+1,cur,ret,target,tot,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vvi ret;
        vi cur;
        dfs(0,cur,ret,target,0,candidates);
        return ret;
    }
};