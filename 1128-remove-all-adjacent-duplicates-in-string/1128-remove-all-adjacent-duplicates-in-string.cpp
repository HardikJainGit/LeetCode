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
    string removeDuplicates(string s) 
    {
        stack<pair<char, int>> st;
        
        for (char c : s) 
        {
            if (!st.empty() && st.top().first == c) 
            {
                st.top().second++;
            } 
            else 
            {
                st.push({c, 1});
            }

            if (st.top().second > 1) 
            {
                st.pop();
            }
        }

        string result = "";

        while (!st.empty()) 
        {
            auto [ch, count] = st.top();
            st.pop();
            result.append(count, ch);
        }

        reverse(result.begin(), result.end());

        return result;
    
    }
};