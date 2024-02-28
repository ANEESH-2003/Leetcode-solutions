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
    void cal(TreeNode* root,int &maxi,int x,int& val)
    {
        if(root==NULL)
            return;
        if(x>maxi)
        {
            maxi=x;
            val=root->val;
        }
        cal(root->left,maxi,x+1,val);
        cal(root->right,maxi,x+1,val);
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxi=-1;
        int val=root->val;
        cal(root,maxi,0,val);
        return val;
    }
};