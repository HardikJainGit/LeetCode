#define vi vector <int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())

class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        unordered_map<char,int> m;
        unordered_map<char,int> occur;

        for(int i=0;i<26;i++)
        {
            occur[i+'a'] = INT_MAX;
        }
        
        for(auto it : words)
        {
            for(int i=0;i<26;i++)
            {
                m[i+'a'] = 0;
            }
            for(auto ch : it)
            {
                m[ch] += 1;
            }
            // debug(m);
            for(int i=0;i<26;i++)
            {
                occur[i + 'a'] = min(occur[i + 'a'],m[i + 'a']);
                m[i + 'a'] = INT_MAX;
            }
            // debug(occur);
        }

        int n = sz(words);
        vector<string> ret;

        for(auto it : occur)
        {
            if(it.ss != INT_MAX)
            {
                while(it.ss)
                {
                    ret.pb(string(1,it.ff));
                    it.ss -= 1;
                }
            }
        }

        return ret;
    }
};