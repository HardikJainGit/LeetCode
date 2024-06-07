#define py cout << "YES\n";
#define pn cout << "NO\n";
#define vi vector <long long>
#define vvi vector<vector<long long>>
#define vp vector<pair<long long,long long>>
#define pi pair<long long,long long>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) long long x; cin>>x;
#define f(b) for(long long i=0;i<b;i++)
#define fz(i,a,b) for(long long i=a;i<b;i++)
#define inp(a,n) long long a[n]; fz(i,0,n) cin>>a[i];
#define inpv(a,n) vector <long long> a; fz(i,0,n) {long long x; cin>>x; a.pb(x);}
#define endl '\n'
#define pr(x) cout<<x<<endl;
#define sz(x) ((long long)(x).size())


// struct TreeNode
// {
//     long long val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:

    void dfs(TreeNode* root , int targetSum , int &cc,long long sum)
    {
        // ^^
        // --

        if(!root)
        {
            return;
        }

        if(sum + root -> val == targetSum)
        {
            cc += 1;
        }

        dfs(root -> right , targetSum , cc , sum + root ->val);
        dfs(root -> left , targetSum , cc ,sum + root -> val);

    }

    void dfs_p(TreeNode* root , int targetSum , int&cc)
    {
        if(!root)
        {
            return;
        }

        dfs(root,targetSum,cc,0);
        dfs_p(root->right,targetSum,cc);
        dfs_p(root->left,targetSum,cc);
    }

    int pathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
        {
            return 0;
        }
        int cc = 0;
        dfs_p(root , targetSum , cc);
        return cc;
    }
};