#include <bits/stdc++.h>
using namespace std;

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

    Trie() 
    {
        root = new TrieNode();
    }

    void insert(int num) 
    {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) 
        {
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

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> ret(queries.size(), 0);

        vector<pair<int, pair<int,int>>> q; // mi {xi , i}

        sort(nums.begin(), nums.end());

        int ix = 0;

        for (auto& it : queries) 
        {
            q.push_back({it[1], {it[0], ix}});
            ix += 1;
        }

        sort(q.begin(), q.end());

        int i = 0;
        int n = nums.size();

        Trie trie;

        for (auto& it : q) 
        {
            while (i < n && nums[i] <= it.first)  // valid
            {
                trie.insert(nums[i]);
                i++;
            }
            if (i != 0) 
            {
                // ret [ix] = xor for xi
                ret[it.second.second] = trie.findMaxXOR(it.second.first);
            } 
            else 
            {
                // nums[i] 's min  > mi
                ret[it.second.second] = -1;
            }
        }
        return ret;
    }
};