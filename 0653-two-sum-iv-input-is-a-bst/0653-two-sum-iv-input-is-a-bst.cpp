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
    map<int,int> m;
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return 0;
        bool x=m[k-root->val];
        m[root->val]++;
        x=x|findTarget(root->left,k);
        x=x|findTarget(root->right,k);
        return x;
    }
};