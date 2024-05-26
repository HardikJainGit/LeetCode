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
    void dfs(int ix ,vvi &ret ,vi nums)
    {
        if (ix == nums.size()) 
        {
            ret.push_back(nums);
            return;
        }

        int pop;

        fz(i,ix,sz(nums))
        {
            swap(nums[i], nums[ix]);
            dfs(ix+1,ret,nums);
            swap(nums[i], nums[ix]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vvi ret;
        vi cur;
        dfs(0,ret,nums);
        return ret;
    }
};