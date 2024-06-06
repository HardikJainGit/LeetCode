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

class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        int n = sz(nums);
        if (n % k)
        {
            return false;
        }

        map<int, int> m;

        f(n)
        {
            m[nums[i]] += 1;
        }

        // debug(m);

        for (auto &it : m)
        {
            // debug(it);
            // debug(m);
            
            while(it.ss)
            {
                if (it.ss == 0)
                {
                    continue;
                }

                it.ss -= 1;

                bool f = true;

                fz(i, 1, k)
                {
                    if (m.find(it.ff + i) == m.end() || m[it.ff + i] == 0)
                    {
                        f = false;
                        break;
                    }
                }
                if (!f)
                {
                    return false;
                }
                fz(i, 1, k)
                {
                    m[it.ff + i] -= 1;
                }
                // debug(m);
            }
        }

        for (auto it : m)
        {
            if (it.ss)
            {
                return false;
            }
        }

        return true;
    }
};
