class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            bool foundX = false;
            bool foundY = false;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == x) foundX = true;
                if (node->val == y) foundY = true;

                // Check if they have same parent
                if (node->left && node->right) {
                    int leftVal = node->left->val;
                    int rightVal = node->right->val;

                    if ((leftVal == x && rightVal == y) ||
                        (leftVal == y && rightVal == x)) {
                        return false; // same parent
                    }
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (foundX && foundY) return true;
            if (foundX || foundY) return false;
        }

        return false;
    }
};
