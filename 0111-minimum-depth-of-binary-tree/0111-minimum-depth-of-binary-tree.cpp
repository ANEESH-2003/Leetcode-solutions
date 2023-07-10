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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        int c=0;
        q.push(root);
        while(!q.empty())
        {
            c++;
            int s=q.size();
            while(s--)
            {
                TreeNode* f=q.front();
                q.pop();
                if(f->left==NULL && f->right==NULL)
                    return c;
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
        }
        return c;
    }
};