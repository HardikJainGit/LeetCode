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

struct DSU
{
    int n;
    vi p;
    DSU(int n)
    {
        p.assign(n + 1,0);
        fz(i,1,n+1)
        p[i] = i;
    }
    int par(int i)
    {
        if (p[i] == i)
        return i;
        return p[i] = par(p[i]);
    }
    void un(int u,int v)
    {
        u = par(u),v = par(v);
        if(u==v) return;
        p[v] = u;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) 
    {
        int ac = accountList.size();
        DSU dsu(ac);
        
        unordered_map<string, int> emailGroup;
        
        for (int i = 0; i < ac; i++) 
        {
            int acz = accountList[i].size();

            for (int j = 1; j < acz; j++) 
            {
                string email = accountList[i][j];
                string acn = accountList[i][0];
                
                // assign email to owner's index

                if (emailGroup.find(email) == emailGroup.end()) 
                {
                    emailGroup[email] = i;
                } 
                else 
                {
                    // email found again -> merge with previous owner's index
                    dsu.un(i, emailGroup[email]);
                }
            }
        }
    
        // Merge other emails corresponding to the mail's owner's index
        // processing john00@mail.com to index 0

        unordered_map<int, vector<string>> f_email;

        for (auto it : emailGroup) 
        {
            string email = it.ff;
            int i = it.ss;
            f_email[dsu.par(i)].push_back(email); // all final emails 
        }

        // Sort the f_email and add the account name

        vector<vector<string>> ret_ac;

        for (auto it : f_email) 
        {
            int i = it.ff;
            
            vector<string> mail = {accountList[i][0]};

            mail.insert(mail.end(), it.ss.begin(),it.ss.end());

            sort(mail.begin() + 1, mail.end());

            ret_ac.push_back(mail); // Push entry of the final owner at index i
        }
        
        return ret_ac;
    }
};

// [["John","johnsmith@mail.com","john_newyork@mail.com"],
// ["John","johnsmith@mail.com","john00@mail.com"],
// ["Mary","mary@mail.com"],
// ["John","johnnybravo@mail.com"]]