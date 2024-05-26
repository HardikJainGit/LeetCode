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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        unordered_map<int,int> m;
        
        f(sz(nums2))
        {
            m[nums2[i] * k] += 1;
        }

        long long ret = 0;

        for(auto it : nums1)
        {
            int sqrt_n = sqrt(it);
            fz(i,1,sqrt_n+1)
            {
                if ((it) % i == 0) 
                {   
                    ret += m[i];
                    if ((it) / i != i) 
                    { 
                        ret += m[(it)/i];
                    }
                }
            }
        }
        return ret;
    }
};
