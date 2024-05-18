class Codec {
public:

    string levelOrder(TreeNode* root) 
    {
        if (!root) 
        {
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);
        string ret;

        while (!q.empty()) 
        {
            int k = q.size();
            bool hasNonNull = false;

            for (int i = 0; i < k; i++) 
            {
                TreeNode* cur = q.front();
                q.pop();

                if (!cur) 
                {
                    ret += "null ";
                } 
                else 
                {
                    ret += to_string(cur->val) + " ";
                    q.push(cur->left);
                    q.push(cur->right);
                    hasNonNull = true; // At least one non NULL in a level
                }
            }

            if (!hasNonNull) // Implies given level is all NULL
            {
                // auto pos = ret.find_last_not_of("null ");
                // if (pos != string::npos) 
                // {
                //     ret.erase(pos + 1); // remove all chars from pos + 1 till end
                // }
                // break;

                for(int i = ret.length() - 1; i>=0 ; i--)
                {
                    if(ret[i] == 'n' || ret[i] == 'u' || ret[i] == 'l' || ret[i] == ' ')
                    {
                        ret.pop_back();
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
    }

        if (!ret.empty() && ret.back() == ' ') 
        {
            ret.pop_back();
        }

        return ret;
    }

    string serialize(TreeNode* root) 
    {
        string ret = levelOrder(root);
        // debug(ret);
        return ret;
    }

    TreeNode* deserialize(string data) 
    {
        // debug(data);

        if(!data.length())
        {
            return NULL;
        }

        stringstream s(data);
        string val;
        s >> val; // extracts a string from the stringstream and stores till whitespace comes

        if (val == "null") 
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) 
        {
            TreeNode* node = q.front();
            q.pop();

            if (!(s >> val)) 
            break;

            if (val != "null") 
            {
                if (isdigit(val[0]) || (val[0] == '-' && isdigit(val[1]))) 
                {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
                else 
                {
                    node->left = NULL;
                }
            }

            if (!(s >> val)) 
            break;

            if (val != "null") 
            {
                if (isdigit(val[0]) || (val[0] == '-' && isdigit(val[1]))) 
                {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
                else 
                {
                    node->right = NULL;
                }
            }
        }
        
        return root;
    }

};
