/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans=NULL;
    int cal(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
            return 0;
        int l=cal(root->left,p,q);
        int r=cal(root->right,p,q);
        l+=r;
        if(root==p || root==q)
            l++;
        if(l==2 && !ans)
            ans=root;
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        cal(root,p,q);
        return ans;
    }
};