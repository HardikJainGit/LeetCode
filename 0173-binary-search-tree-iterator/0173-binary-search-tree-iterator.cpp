class BSTIterator {
private:

    vector<int> inorder;
    int index = 0;

    void inorderTraversal(TreeNode* root,vector<int> &v) 
    {
        
        TreeNode* cur = root;

        while(cur)
        {
            if(!cur->left)
            {
                v.push_back(cur->val);
                cur = cur -> right;
            }
            else
            {
                TreeNode* prev = cur -> left;  

                while(prev -> right && prev -> right != cur)
                {
                    prev = prev -> right;
                }

                if(!prev -> right)
                {
                    prev -> right = cur;
                    cur = cur -> left;
                }

                else
                {
                    prev -> right = NULL;
                    v.push_back(cur->val);
                    cur = cur -> right;
                }
            }
            
        }
    }

public:
    BSTIterator(TreeNode* root)
    {
        inorderTraversal(root, inorder);
    }

    int next() 
    {
        return inorder[index++];
    }

    bool hasNext() 
    {
        return index < inorder.size();
    }
};
