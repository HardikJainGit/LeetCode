class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector <int> v;
        TreeNode* cur = root;

        //LNR

        while(cur)
        {
            if(!cur->left)
            {
                v.push_back(cur->val);
                cur = cur -> right;
            }
            else
            {
                // rightmost of left
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

        return v;
    }

    bool isSorted(vector<int>& vec) 
    {
        bool f = true;
        
        for (int i = 1; i < vec.size(); i++) 
        {
            if (vec[i - 1] >= vec[i]) {
                f = false;
            }
        }
            return f;
    }
    
    
    
    bool isValidBST(TreeNode* root) 
    {
        vector<int> inorder;
        inorder = inorderTraversal(root);
        return isSorted(inorder);
    }   
};