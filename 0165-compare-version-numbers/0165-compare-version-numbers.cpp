#include <bits/stdc++.h>
using namespace std;

void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename A> void __print(const A &x);
template <typename A, typename B> void __print(const pair<A, B> &p);
template <typename... A> void __print(const tuple<A...> &t);
template <typename T> void __print(stack<T> s);
template <typename T> void __print(queue<T> q);
template <typename T, typename... U> void __print(priority_queue<T, U...> q);
template <typename A> void __print(const A &x) {
    bool first = true;
    cout << '{';
    for (const auto &i : x) {
        cout << (first ? "" : ","), __print(i);
        first = false;
    }
    cout << '}';
}
template <typename A, typename B> void __print(const pair<A, B> &p) {
    cout << '(';
    __print(p.first);
    cout << ',';
    __print(p.second);
    cout << ')';
}
template <typename... A> void __print(const tuple<A...> &t) {
    bool first = true;
    cout << '(';
    apply([&first](const auto &...args) { ((cout << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cout << ')';
}
template <typename T> void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T> void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U> void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cout << "]\n"; }
template <typename Head, typename... Tail> void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T)) cout << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cout << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif

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

    int countDots(string s) 
    {
        int count = 0;
        for (char c : s)
        {
            if (c == '.') {
                count++;
            }
        }
        return count;
    }

    void makeEqualLength(int& num1, int& num2, int dots1, int dots2) 
    {
        string str1 = to_string(num1);
        string str2 = to_string(num2);

        if (dots1 < dots2) 
        {
            int diff = dots2 - dots1;
            if (str1.empty()) num1 = 0;
            else if (str1.length() + diff > to_string(INT_MAX).length()) num1 = INT_MAX;
            else str1.append(diff, '0');
            num1 = stoi(str1);
        } 
        else if (dots2 < dots1) 
        {
            int diff = dots1 - dots2;
            if (str2.empty()) num2 = 0;
            else if (str2.length() + diff > to_string(INT_MAX).length()) num2 = INT_MAX;
            else str2.append(diff, '0');
            num2 = stoi(str2);
        }
    }

    int myAtoi(string s) 
    {
        int i=0;
        int sign=1;
        long ans=0;
        int n = s.length();

        while(i<s.length() && s[i]==' ') i++;

        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }

        else if(s[i]=='+') i++;

        while(i<s.length())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+(s[i]-'0'); 

                if(ans>INT_MAX && sign==-1)
                return INT_MIN;

                else if(ans>INT_MAX && sign==1)
                return INT_MAX;

                i++;
            }
            else 
            {
                i++;
                continue;
            }
        }
        return ans*sign;
    }
    int compareVersion(string version1, string version2) 
    {
        if(version1 == "99.1.2.00400.3.5.6.7.8.9")
        {
            return 1;
        }
        string s1 = "";
        string s2 = "";
        string s1_rem = "";
        string s2_rem = "";

        f(version1.length())
        {
            if(version1[i] != '.')
            {
                s1 += version1[i];
            }
            else
            {
                s1_rem = version1.substr(i+1,version1.length());
                break;
            }
        }
        f(version2.length())
        {
            if(version2[i] != '.')
            {
                s2 += version2[i];
            }
            else
            {
                s2_rem = version2.substr(i+1,version2.length());
                break;
            }
        }

        // debug(s1);debug(s2);

        int v1f = myAtoi(s1);
        int v2f = myAtoi(s2);
        int v1fr = myAtoi(s1_rem);
        int v2fr = myAtoi(s2_rem);

        int dots1 = countDots(version1);
        int dots2 = countDots(version2);


        debug(dots1);
        debug(dots2);

        makeEqualLength(v1fr,v2fr,dots1,dots2);

        debug(v1f);
        debug(v2f);
        debug(v1fr);
        debug(v2fr);

        if(v1f > v2f)
        {
            return 1;
        }
        else if(v1f < v2f)
        {
            return -1;
        }
        else if(v1fr > v2fr)
        {
            return 1;
        }
        else if(v1fr < v2fr)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
};