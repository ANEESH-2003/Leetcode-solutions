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
    void cal(vector<int>& v,TreeNode* root)
    {
        if(!root)
            return ;
        cal(v,root->left);
        v.push_back(root->val);
        cal(v,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        cal(v,root);
        return v;
    }
};