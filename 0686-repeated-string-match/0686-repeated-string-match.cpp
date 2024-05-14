class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string s = a;
        
        while(a.find(b) == string::npos && a.length() < b.length())
        {
            a += s;
            count += 1;
        }
        if(a.find(b) != string::npos)
        {
            return count + 1;
        }
        a += s;
        count += 1;
        if(a.find(b) != string::npos)
        {
            return count + 1;
        }
        return -1;
    }
};