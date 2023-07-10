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
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& v,int p=INT_MAX) {
        if(i==v.size() || v[i]>p)
            return NULL;
        TreeNode* t=new TreeNode(v[i++]);
        t->left=bstFromPreorder(v,t->val);
        t->right=bstFromPreorder(v,p);
        return t;
    }
};