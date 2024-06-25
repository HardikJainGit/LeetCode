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
    int f = 0;

    void inorderHelper(TreeNode* node) 
    {
        if (node == nullptr) 
        {
            return;
        }
        inorderHelper(node->right);

        f += node -> val;

        node -> val = f;
        
        inorderHelper(node->left);
    }
    TreeNode* bstToGst(TreeNode* root) 
    {
        // huhu
        vi in;
        inorderHelper(root);
        return root;
    }
};