class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.empty() || inorder.empty()) 
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        stack<TreeNode*> st;

        st.push(root);
        int inorderIndex = 0;

        for(int i = 1; i < preorder.size(); i++) 
        {
            TreeNode* currentNode = st.top();

            // go to left leaf

            if(currentNode->val != inorder[inorderIndex]) 
            {
                currentNode->left = new TreeNode(preorder[i]);
                st.push(currentNode->left);
            } 
            
            else 
            {
                while(!st.empty() && st.top()->val == inorder[inorderIndex]) 
                {
                    currentNode = st.top();
                    st.pop();
                    ++inorderIndex;
                }
                
                currentNode->right = new TreeNode(preorder[i]);
                st.push(currentNode->right);
            }
        }

        return root;
    }
};
