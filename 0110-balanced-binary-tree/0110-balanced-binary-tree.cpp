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
    bool ans=1;
    int cal(TreeNode* root)
    {
        if(!root)
            return 0;
        int l=cal(root->left);
        int r=cal(root->right);
        ans&=abs(l-r)<=1?1:0;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        cal(root);
        return ans;
    }
};