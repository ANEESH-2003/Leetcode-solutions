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
    bool isEvenOddTree(TreeNode* root) {
        bool isEvenLevel = true;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int prev = isEvenLevel ? 0 : INT_MAX;
            for(int i=0;i<size;i++) {
                auto p = q.front();
                q.pop();
                if(isEvenLevel && (prev >= p->val || (p->val)%2 == 0)) {
                    return false;
                }
                if(!isEvenLevel && ((prev <= p->val || (p->val)%2 !=0))) {
                    return false;
                }
                prev = p->val;

                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            isEvenLevel = !isEvenLevel;
        }
        return true;
    }
};