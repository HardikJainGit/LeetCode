class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if (!root) {
            return 0;
        }

        queue<pair<TreeNode*, unsigned long long>> q; // Node, Position
        q.push({root, 1}); 

        int maxWidth = 0;

        while (!q.empty()) {
            unsigned long long lpos = q.front().second;
            unsigned long long rpos = lpos;
            unsigned long long level = q.size(); // Level size

            for (unsigned long long i = 0; i < level; ++i) 
            { // Process current level
                auto it = q.front();
                TreeNode* cur = it.first;
                unsigned long long pos = it.second;
                q.pop();

                rpos = pos;

                if (cur->left) q.push({cur->left, 2 * pos});
                if (cur->right) q.push({cur->right, 2 * pos + 1});
            }
            maxWidth = max(maxWidth, static_cast<int>(rpos - lpos + 1)); 
        }

        return maxWidth;
    }
};
