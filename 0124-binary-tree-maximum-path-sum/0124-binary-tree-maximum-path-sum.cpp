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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findAns(root,maxi);
        return maxi;
    }
    int findAns(TreeNode* root,int &maxi)
    {
        if(root==nullptr) return 0;
        int ls=max(0,findAns(root->left,maxi));
        int rs=max(0,findAns(root->right,maxi));
        maxi=max(maxi,root->val+ls+rs);
        return max(ls,rs)+root->val;
    }
};