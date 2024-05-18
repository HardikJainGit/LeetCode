class Codec {
public:

    void dfs_s(TreeNode* root , string &s)
    {
        if(!root)
        {
            s += "N ";
            return;
        }
        s += to_string(root -> val) + ' ';
        dfs_s(root -> left,s);
        dfs_s(root -> right,s);
    }
    string serialize(TreeNode* root) 
    {
        string s;
        dfs_s(root,s);
        cout << s;
        return s;
    }

    TreeNode* dfs(stringstream &s) {
            string str;
            if (!(s >> str)) 
            {
                return NULL;
            }
            // cout << str;
            if (str == "N") 
            {
                return NULL;
            }
            TreeNode* root = new TreeNode(stoi(str));
            root->left = dfs(s);
            root->right = dfs(s);
            return root;
        }

        TreeNode* deserialize(string data) 
        {
            stringstream s(data);
            return dfs(s);
        }
    };
