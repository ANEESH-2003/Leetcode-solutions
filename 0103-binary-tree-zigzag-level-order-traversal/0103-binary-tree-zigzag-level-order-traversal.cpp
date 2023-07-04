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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        int c=0;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            vector<int> f;
            while(s--)
            {
                TreeNode* t=q.front();
                q.pop();
                f.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(c++%2)
                reverse(f.begin(),f.end());
            v.push_back(f);
        }
        return v;
    }
};