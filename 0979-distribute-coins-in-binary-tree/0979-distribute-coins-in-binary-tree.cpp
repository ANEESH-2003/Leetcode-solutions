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
    int ans=0;
    int cal(TreeNode* root)
    {
        if(!root)
            return 0;
        int t=root->val;
        t+=cal(root->left);
        t+=cal(root->right);
        t--;
        ans+=abs(t);
        return t;
    }
    int distributeCoins(TreeNode* root) {
        cal(root);
        return ans;
    }
};