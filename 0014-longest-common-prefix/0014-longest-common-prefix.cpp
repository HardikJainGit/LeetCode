class Solution {
public:

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char data) {
            this->data = data;
            this->isTerminal = false;
            this->childCount = 0;

            for(int i=0; i<26; i++) {
                this->children[i] = NULL;
            }
        }
};

class Trie {
    public:
        TrieNode* root=new TrieNode('\0');

        // Trie() {
        //     root = new TrieNode('\0');
        // }

        void insertUtil(TrieNode* root, string word) {
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            // Assuming the string is in lowercase
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] == NULL) { 
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            } else {
                child = root->children[index]; //update child 
            }

            insertUtil(child, word.substr(1));
        }

        void insertNode(string word) {
            insertUtil(root, word);
        }
};

/* TC and SC both (O(M*N)) */

string longestCommonPrefix(vector<string>& strs) 
{
    string ans = "";
    Trie* t = new Trie();

    // insert all strings in trie;
    for(int i=0; i<strs.size(); i++) 
    {
        if(strs[i] == "")
        {
            return "";
        }
        t->insertNode(strs[i]);
    }

    TrieNode* temp = t->root;

    for(int i=0; i<strs[0].length(); i++) {
        if(temp->childCount == 1) {
            ans.push_back(strs[0][i]); //push chars with only one child

            int index = strs[0][i] - 'a';
            temp = temp->children[index]; //update temp
        } 
        
        else {
            break;
        }

        if(temp->isTerminal) {  //for 2 words AGE and A ans will be 2 but we need 1
            break;
        }
    }

    return ans;
    }
};