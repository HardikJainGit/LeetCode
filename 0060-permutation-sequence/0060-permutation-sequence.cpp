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
    string getPermutation(int n, int k) 
    {
        vi factorial(n, 1);
        vi numbers;

        fz(i, 1, n) 
        {
            factorial[i] = factorial[i - 1] * i;
        }

        fz(i, 1, n + 1) 
        {
            numbers.pb(i);
        }
        
        k -= 1;
        
        string ret = "";
                
        for (int i = n; i > 0; i--) 
        {
            int index = k / factorial[i - 1];
            ret += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= factorial[i - 1];
        }
        
        return ret;
    }
};


