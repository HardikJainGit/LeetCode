class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> v;
        if (root == NULL) return v;

        stack<TreeNode*> s;
        TreeNode* lastVisited = NULL;
        TreeNode* current = root;

        while (current || !s.empty()) 
        {
            // go to extreme left
            if (current) 
            {
                s.push(current);
                current = current->left;
            } 
            else 
            {
                TreeNode* node = s.top();

                //if left most node has a right child
                if (node->right && lastVisited != node->right) 
                {
                    current = node->right; //process the subtree of node -> right
                } 

                //either no right node or right node is processed
                else 
                {
                    v.push_back(node->val);
                    lastVisited = node;
                    s.pop();
                }
            }
        }

        return v;
    }
};
