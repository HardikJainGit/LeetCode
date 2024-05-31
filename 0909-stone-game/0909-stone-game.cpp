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
    bool stoneGame(vector<int>& piles) 
    {
        int n = sz(piles);
        int l = 0;
        int r = n - 1;

        int alice = 0;
        int bob = 0;

        bool alice_c = true;
        bool bob_c = false;

        while(l <= r)
        {
            if(piles[l] > piles[r])
            {
                if(alice_c)
                {
                    alice += piles[l];
                    l += 1;
                    alice_c = !alice_c;
                }
                else
                {
                    bob += piles[l];
                    l += 1;
                    alice_c = !alice_c;
                }
            }
            else
            {
                if(alice_c)
                {
                    alice += piles[r];
                    r -= 1;
                    alice_c = !alice_c;
                }
                else
                {
                    bob += piles[r];
                    r -= 1;
                    alice_c = !alice_c;
                }
            }
        }

        return (alice > bob);
    }
};