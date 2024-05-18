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
    int distributeCoins(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        ans+=distributeCoins(root->left);
        ans+=distributeCoins(root->right);
        root->val--;
        root->val+=(root->left)?root->left->val:0;
        root->val+=(root->right)?root->right->val:0;
        ans+=abs(root->val);
        return ans;
    }
};