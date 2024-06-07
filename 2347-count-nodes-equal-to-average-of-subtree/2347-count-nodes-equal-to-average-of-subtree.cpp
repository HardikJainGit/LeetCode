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
    pi dfs(TreeNode* root , int &cc)
    {
        if(!root)
        {
            return {};
        }

        pi r = dfs(root->right,cc); // catch what is returned !!
        pi l = dfs(root->left,cc);

        if(!root -> left && !root -> right)
        {
            cc += 1;
            return {root -> val , 1};
        }
        else
        {
            if((r.ff + l.ff + root -> val) / (l.ss + r.ss + 1) == root -> val)
            {
                cc += 1;
            }
            return {r.ff + l.ff + root -> val , r.ss + l.ss + 1};
        }
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int cc = 0;
        pi r = dfs(root,cc);
        return cc;
    }
};  