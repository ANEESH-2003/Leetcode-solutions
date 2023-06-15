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
    void cal(vector<int>& v,TreeNode* root,int l)
    {
        if(v.size()==l)
            v.push_back(root->val);
        else
            v[l]+=root->val;
        if(root->left)
            cal(v,root->left,l+1);
        if(root->right)
            cal(v,root->right,l+1);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> v;
        cal(v,root,0);
        int maxi=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>v[maxi])
                maxi=i;
        }
        return maxi+1;
    }
};