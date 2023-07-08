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
    int maxi=INT_MIN;
    int cal(TreeNode* root)
    {
        if(!root)
            return 0;
        int l=cal(root->left);
        int r=cal(root->right);
        maxi=max(maxi,max(l+r+root->val,max(l+root->val,max(r+root->val,root->val))));
        return max(root->val,max(root->val+l,root->val+r));
    }
    int maxPathSum(TreeNode* root) {
        int x=cal(root);
        return maxi;
    }
};