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
class Solution {
public:
class TrieNode {
public:
    TrieNode* children[2]; // each node can have 2 children for binary trie

    TrieNode() {
        for (int i = 0; i < 2; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num & (1 << i)); 
            // or use (num >> i) & 1;
            if(bit)
            {
                bit = 1;
            }
            else
            {
                bit = 0;
            }
            if (node->children[bit] == nullptr) 
            {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int findMaxXOR(int num) 
    {
        TrieNode* node = root;

        int maxXOR = 0;

        for (int i = 31; i >= 0; i--) 
        {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;

            if (node->children[oppositeBit] != nullptr) 
            {
                maxXOR |= (1 << i);
                node = node->children[oppositeBit];
            } 
            else 
            {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }

    int findMaximumXOR(vector<int>& nums) 
    {
        int maxXOR = 0;
        for (int num : nums) 
        {
            insert(num);
            maxXOR = max(maxXOR, findMaxXOR(num));
        }
        return maxXOR;
    }
};

int findMaximumXOR(vector<int>& nums) 
{
    Trie trie;
    return trie.findMaximumXOR(nums);
}

};