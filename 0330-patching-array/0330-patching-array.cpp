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
    int minPatches(vector<int>& nums, int n) 
    {
        int cc = 0;
        long long cur = 0;
        int i = 0;

        while(cur < n)
        {
            if(i < sz(nums) && nums[i] <= cur + 1)
            {
                cur += nums[i];
                i += 1;
            }
            else
            {
                cc += 1;
                cur += cur + 1;
            }
            // i += 1;
        }

        return cc;
    }
};