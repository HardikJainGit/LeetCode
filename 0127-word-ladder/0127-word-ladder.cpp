class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }
        unordered_map<string, vector<string>> adj;
        string pattern;
        for(auto word : wordList)
        {
            for(int j = 0; j < word.length(); j++)
            {
                pattern = word.substr(0,j) + '*' + word.substr(j+1,word.length() - j - 1);
                adj[pattern].push_back(word);
            }
        }

        // debug(adj);

        int n = wordList.size();

        queue<string> q;
        unordered_map<string, bool> vis;
        unordered_map<string, string> p;
        unordered_map<string, int> d;
                
        q.push(beginWord);
        vis[beginWord] = true;
        p[beginWord] = '*';
        d[beginWord] = 1;

        int len = 0;
        
        while (!q.empty()) 
        {
            string w = q.front();
            q.pop();
            for(int j = 0; j < w.length(); j++)
            {
                pattern = w.substr(0,j) + '*' + w.substr(j+1,w.length() - j - 1);
                for (auto u : adj[pattern]) 
                {
                    if(u == endWord)
                    {
                        return d[w] + 1;
                    }
                    if (!vis[u]) 
                    {
                        vis[u] = true;
                        q.push(u);
                        d[u] = d[w] + 1;
                        p[u] = w;
                    }
                }
            }
            
        }
        return 0;
    }
};