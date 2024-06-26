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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        inorderHelper(root, v);
        return v;
    }

    int f = 0;

    void inorderHelper(TreeNode* node, vector<int>& v) 
    {
        if (node == nullptr) 
        {
            return;
        }
        inorderHelper(node->left, v);

        v.push_back(node->val);

        inorderHelper(node->right, v);
    }

    TreeNode* dfs(vector<int> nums)
    {
        if(!nums.size())
        {
            return NULL;
        }

        int split = sz(nums)/2; //2
        TreeNode* node = new TreeNode(nums[split]);
        cout<<nums[0];

        vector<int> nums_l (nums.begin(), nums.begin() + split);
        vector<int> nums_r (nums.begin() + split + 1 , nums.end());
        
        node -> right = dfs(nums_r);
        node -> left = dfs(nums_l);

        return node;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        vi inorder;
        inorder = inorderTraversal(root);
        // debug(inorder);
        return dfs(inorder);
    }
};