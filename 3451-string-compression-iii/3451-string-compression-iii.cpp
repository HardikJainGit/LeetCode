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
    string compressedString(string word) 
    {
        string ret = "";
        int j = 0;
        while(j < word.length())
        {
            int cc = 1;
            char t = word[j];
            fz(i,j,word.length() - 1)
            {
                if(word[i] == word[i+1] && cc <=8)
                {
                    t = word[i];
                    cc += 1;
                }
                else
                {
                    break;
                }
            }

            // debug(r);

            ret += to_string(cc) + t;
            j += cc;
            // debug(j);
        }

        return ret;
    }
};