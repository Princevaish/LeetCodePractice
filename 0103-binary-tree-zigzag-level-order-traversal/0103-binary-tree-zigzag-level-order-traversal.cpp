/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root== nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;
        while(!q.empty())
        {
            
            int qsize=q.size();
            vector<int> row(qsize);
            for(int i=0;i<qsize;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(ltr == true)
                {
                    row[i]=node->val;
                }
                else if(ltr == false)
                {
                    row[qsize-1-i]=node->val;
                }
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            ltr=!(ltr);
            res.push_back(row);
        }
        return res;
    }
};