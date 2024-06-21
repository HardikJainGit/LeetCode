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

//Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3

class Solution {
public:
    int extraprofit(vi &customers, vi &grumpy , int m,int l , int r)
    {
        int e = 0;
        fz(i,l,r+1)
        {
            if(grumpy[i])
            {
                e += customers[i];
            }
        }

        return e;
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int cc = 0;
        int n = sz(grumpy);
        
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

        while(r < n)
        {
            int e = extraprofit(customers,grumpy,m,l,r);
            m_e = max(m_e , e);
            l += 1;
            r += 1;
        }

        return cc + m_e;

    }
};