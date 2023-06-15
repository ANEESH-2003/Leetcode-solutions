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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int l=0;
        int maxi=0;
        int mc=root->val;
        q.push(root);
        while(!q.empty())
        {
            int c=q.size();
            int s=0;
            while(c--)
            {
                TreeNode* t=q.front();
                q.pop();
                s+=t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(s>mc)
            {
                mc=s;
                maxi=l;
            }
            l++;
        }
        return maxi+1;
    }
};