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
    int maxi=0;
    void cal(TreeNode* root,int x)
    {
        if(!root)
            return ;
        maxi=max(maxi,x);
        x++;
        cal(root->left,x);
        cal(root->right,x);
    }
    int maxDepth(TreeNode* root) {
        cal(root,1);
        return maxi;
    }
};