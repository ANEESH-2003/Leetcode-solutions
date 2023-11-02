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
    pair<int,int> cal(int &ans,TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int> l={0,0};
        pair<int,int> r={0,0};
        if(root->left)
        {
            l=cal(ans,root->left);
        }
        if(root->right)
        {
            r=cal(ans,root->right);
        }
        if((l.first+r.first+root->val)/(l.second+r.second+1)==root->val)
            ans++;
        return {(l.first+r.first+root->val),(l.second+r.second+1)};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        pair<int,int> x=cal(ans,root);
        return ans;
    }
};