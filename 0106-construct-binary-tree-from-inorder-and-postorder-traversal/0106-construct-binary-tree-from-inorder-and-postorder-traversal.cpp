class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(postorder.empty() || inorder.empty()) 
        {
            return NULL;
        }

        int n = inorder.size();
        TreeNode* root = new TreeNode(postorder[n - 1]); // root is the last element in postorder
        stack<TreeNode*> st;
        st.push(root);
        int inorderIndex = n - 1;

        for(int i = n - 2; i >= 0; i--) 
        {
            TreeNode* currentNode = st.top();

            // go to right leaf
            if(currentNode->val != inorder[inorderIndex]) 
            {
                currentNode->right = new TreeNode(postorder[i]);
                st.push(currentNode->right);
            } 
            else 
            {
                while(!st.empty() && st.top()->val == inorder[inorderIndex]) 
                {
                    currentNode = st.top();
                    st.pop();
                    --inorderIndex;
                }

                currentNode->left = new TreeNode(postorder[i]);
                st.push(currentNode->left);
            }
        }

        return root;
    }
};
