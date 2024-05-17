class BSTIterator {
public:

    stack <TreeNode*> st;

    BSTIterator(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root = root -> left;
        }
    }

    int next() 
    {
        TreeNode* nxt_small = st.top();
        st.pop();
        int ret = nxt_small -> val;
        TreeNode* cur = nxt_small -> right;

        if(cur)
        {
            while(cur)
            {
                st.push(cur);
                cur = cur -> left;
            }
        }
        return ret;
    }

    bool hasNext() 
    {
        return st.size();
    }
};
