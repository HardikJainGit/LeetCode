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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
 
class Solution {
public:
    // void dfs(int &res , TreeNode* node,unordered_map<TreeNode* , pi> &m)
    // {
    //     if(!node)
    //     {
    //         return;
    //     }

    //     dfs(res,node->right,m);
    //     dfs(res,node->left,m);

    //     if(!node -> left && !node -> right)
    //     {
    //         m[node] = {1,node -> val};
    //     }
    //     else if (!node->right && node->left)
    //     {
    //         m[node] = {1 + m[node->left].ff , m[node->left].ss + node->val};
    //     }
    //     else if (!node->left && node->right)
    //     {
    //         m[node] = {1 + m[node->right].ff , m[node->right].ss + node->val};
    //     }
    //     else
    //     {
    //         m[node] = {1 + m[node->right].ff + m[node->left].ff , m[node->right].ss + m[node->left].ss + node->val};
    //     }

    //     res += abs(m[node].ff - m[node].ss);
        
    //     // return (node->left->val - 1 + node->right->val - 1);
    //     return;
    // }
    void dfs(int &res , TreeNode* node,unordered_map<TreeNode* , int> &m)
    {
        if(!node)
        {
            return;
        }

        dfs(res,node->right,m);
        dfs(res,node->left,m);

        if(!node -> left && !node -> right)
        {
            m[node] = (-1 + node -> val);
        }
        else if (!node->right && node->left)
        {
            m[node] = (m[node->left] + node->val - 1);
        }
        else if (!node->left && node->right)
        {
            m[node] = (-1 + m[node->right] + node->val);
        }
        else
        {
            m[node] = (-1 + m[node->left] + m[node->right] + node->val);
        }

        res += abs(m[node]);
        
        // return (node->left->val - 1 + node->right->val - 1);
        return;
    }
    int distributeCoins(TreeNode* root) 
    {
        unordered_map<TreeNode* , int> m; // sz coins
        int res = 0;
        dfs(res,root,m);
        return res;
    }
};
