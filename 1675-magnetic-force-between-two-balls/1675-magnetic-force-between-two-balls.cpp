#include <bits/stdc++.h>
using namespace std;

#define py cout << "YES\n";
#define pn cout << "NO\n";
#define vi vector <int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; fz(i,0,n) {int x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())


class Solution {
public:
    int n;
    bool condition(int force, vector<int>& position, int m)
    {
        int x=position[0];
        int balls=1;

        for(int i=1; i<n && balls<=m; i++)
        {
            if (position[i]-x>=force)
            {
                x=position[i];
                balls++;
            }
        }
        return balls>=m;
    }
    int maxDistance(vector<int>& position, int m) 
    {
        srt(position);

        n = sz(position);

        if(sz(position) == 2)
        {
            return position.back() - position[0];
        }
        
        int ret = INT_MAX;

        fz(i,1,sz(position))
        {
            ret = min(ret , position[i] - position[i-1]);
        }

        if(m == sz(position))
        {
            return ret;
        }

        long long lo = ret - 1;
        long long hi = position.back() - position[0] + 1;
        long long mid = 0;

        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
    
            if (!condition(mid,position,m))
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        return lo;
    }
};