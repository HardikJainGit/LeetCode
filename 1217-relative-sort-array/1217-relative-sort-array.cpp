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

    static bool customCompare(int& a, int& b, vector<int>& arr2,unordered_map <int,int> &m) 
    {
        // auto itA = find(arr2.begin(), arr2.end(), a);
        // auto itB = find(arr2.begin(), arr2.end(), b);

        // if (itA == arr2.end() && itB == arr2.end()) 
        // {
        //     return a < b; // ascending if not present in arr2
        // }

        // sort on index in arr2

        // return distance(arr2.begin(), itA) < distance(arr2.begin(), itB);

        // If both elements are not in arr2
        if (m[a] == 0 && m[b] == 0) 
        {
            return a < b; // Sort in ascending order
        }

        // If one element is not in arr2, treat it as having INT_MAX priority
        if (m[a] == 0) return false; // a should go after b m[a] = INT_MAX
        if (m[b] == 0) return true;  // b should go after a m[b] = INT_MAX

        // Sort based on the custom order given in arr2
        return m[a] < m[b];
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_map <int,int> m;

        f(sz(arr2))
        {
            m[arr2[i]] = i + 1;
        }
        
        sort(arr1.begin(), arr1.end(), [&arr2 , &m](int& a, int& b)
        {
            return customCompare(a, b, arr2, m);
        });

        return arr1;
    }
};