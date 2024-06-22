// jo tu mil gaya deewane bane
// ham tere pyar mai muskurane lage

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
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n = sz(nums);
        f(n)
        {
            if(nums[i]%2)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }

        vi pr(n+1);

        pr[0] = 0;

        f(n)
        {
            pr[i+1] = pr[i] + nums[i];
        }

        int l = 0;
        int r = 1;
        int cc = 0;

        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1;

        fz(r,1,n+1)
        {
            // The two sum logic used to get number of pairs with difference of k !
            // Do not use two pointers to get number of pairs with difference k !
            // Remember !

            if(prefix_count.find(pr[r] - k) != prefix_count.end())
            {
                cc += prefix_count[pr[r] - k];
            }

            prefix_count[pr[r]] += 1;
        }

        return cc;
    }
};