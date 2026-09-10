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
    TreeNode* buildtree(vector<int> &postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend,unordered_map<int,int>&mp)
    {
       if(instart>inend || poststart>postend) return NULL;
       TreeNode* node= new TreeNode(postorder[postend]);
       int inroot=mp[node->val];
       int numsleft=inroot-instart;
       int numsright=inend-inroot;
       node->left=buildtree(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,mp);
       node->right=buildtree(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,mp);
       return node;



    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *root=buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};