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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int cc = 0;
        int n = sz(grumpy);

        // find total satisfied customers
        
        f(n)
        {
            if(!grumpy[i])
            {
                cc += customers[i];
            }
        }

        int m = minutes;

        int l = 0;
        int r = m - 1;
        int m_e = INT_MIN;
        int ret = cc;

        int unsatis = 0;

        // find unsatisfied customers in the first sliding window

        f(m)
        {
            if (grumpy[i]) 
            {
                unsatis += customers[i];
            }
        }

        m_e = unsatis;

        // find the maximum unsatisfied customers in any sliding window

        fz(i,m,n)
        {
            if(grumpy[i-m])
            {
                unsatis -= customers[i-m];
            }
            if(grumpy[i])
            {
                unsatis += customers[i];
            }
            m_e = max(m_e , unsatis);
        }

        // convert the unsatisfied customers to satisfied customers

        return cc + m_e;

    }
};