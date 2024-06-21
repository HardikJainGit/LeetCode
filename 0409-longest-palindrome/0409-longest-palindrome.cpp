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
    int longestPalindrome(string s) 
    {
        unordered_map<char,int> m;

        f(s.length())
        {
            m[s[i]] += 1;
        }

        int of = 0;
        int cc = 0;

        for(auto it : m)
        {
            if(it.ss % 2)
            {
                of = 1;
                cc += it.ss - 1;
            }
            else if(it.ss % 2 == 0)
            {
                cc += it.ss;
            }
        }

        return (cc) + of;
    }
};