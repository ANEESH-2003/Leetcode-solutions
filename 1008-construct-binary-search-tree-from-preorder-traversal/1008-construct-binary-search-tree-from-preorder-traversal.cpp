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
    TreeNode* bstFromPreorder(vector<int>& preorder,int maxi=INT_MAX,int mini=INT_MIN) {
        if(i==preorder.size() || preorder[i]>=maxi || preorder[i]<=mini)
            return NULL;
        int v=preorder[i];
        i++;
        TreeNode* root=new TreeNode(v,bstFromPreorder(preorder,v,mini),bstFromPreorder(preorder,maxi,v));
        return root;
    }
};