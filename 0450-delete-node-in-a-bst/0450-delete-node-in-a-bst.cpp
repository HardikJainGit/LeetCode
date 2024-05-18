class Solution {
public:

    TreeNode* findMin(TreeNode* node) 
    {
        TreeNode* cur = node;
        while (cur && cur->left) 
        {
            cur = cur->left;
        }
        return cur;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root) 
        {
            return NULL;
        }

        if (key < root->val) 
        {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) 
        {
            root->right = deleteNode(root->right, key);
        } 
        else {
            if (!root->left) 
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) 
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};
