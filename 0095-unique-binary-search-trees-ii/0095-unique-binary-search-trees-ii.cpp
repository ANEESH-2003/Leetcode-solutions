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
    vector<TreeNode*> cal(int l,int r)
    {
        if(r<l)
            return {NULL};
        vector<TreeNode*> ans;
        for(int i=l;i<=r;i++)
        {
            vector<TreeNode*> vl,vr;
            vl=cal(l,i-1);
            vr=cal(i+1,r);
            for(auto j:vl)
            {
                for(auto k:vr)
                {
                    ans.push_back(new TreeNode(i,j,k));
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return cal(1,n);
    }
};