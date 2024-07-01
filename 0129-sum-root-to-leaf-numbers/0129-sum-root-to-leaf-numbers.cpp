#include<bits/stdc++.h>
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
  public:
    int ret = 0;
    void findPaths(TreeNode* node, vector<int>& currentPath, vector<vector<int>>& allPaths) 
    {
        if (!node) 
        {
            return;
        }

        currentPath.push_back(node->val);

        // If it's a leaf node, add the current path to allPaths
        if (!node->left && !node->right) 
        {
            allPaths.push_back(currentPath);
        } 
        else 
        {
            // Otherwise, traverse the left and right subtrees
            findPaths(node->left, currentPath, allPaths);
            findPaths(node->right, currentPath, allPaths);
        }

        // Backtrack to explore other paths
        currentPath.pop_back();
    }
    vector<vector<int>> Paths(TreeNode* root) {
        vvi v;
        if(!root)
        {
            return v;
        }
        if (!root->left && !root->right) 
        {
            v.push_back({root->val});
            return v;
        }
        vi r;
        findPaths(root,r,v);
        return v;
    }
    int sumNumbers(TreeNode* root) 
    {
        vvi paths;
        paths = Paths(root);

        for(auto it : paths)
        {
            int s = sz(it);
            f(s)
            {
                ret += it[i] * pow(10,s-i-1);
            }
        }

        return ret;
    }
};