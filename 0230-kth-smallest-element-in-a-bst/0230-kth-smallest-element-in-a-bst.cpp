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
    int x=0;
    void cal(TreeNode* root,int& k)
    {
        if(!root)
            return;
        cal(root->left,k);
        if(x==k-1)
            ans=root->val;
        x++;
        cal(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        cal(root,k);
        return ans;
    }
};