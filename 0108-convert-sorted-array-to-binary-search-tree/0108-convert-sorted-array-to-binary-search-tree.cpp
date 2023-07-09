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
    TreeNode* cal(vector<int>& v,int l,int r)
    {
        if(r<l)
            return NULL;
        if(l==r)
            return new TreeNode(v[l]);
        int m=(l+r)/2;
        return new TreeNode(v[m],cal(v,l,m-1),cal(v,m+1,r));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return cal(nums,0,nums.size()-1);
    }
};