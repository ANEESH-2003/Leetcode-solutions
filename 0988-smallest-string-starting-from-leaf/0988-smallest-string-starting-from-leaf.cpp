class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        stack<pair<TreeNode*, string>> S;
        S.push(make_pair(root, ""));

        while (!S.empty()) {
            auto p = S.top(); S.pop();
            auto node = p.first;
            auto& prev = p.second;
            string curr = string(1, 'a'+ node->val) + prev;

            if (!node->left && !node->right) {
                if (result == "" || curr < result) {
                    result = curr;
                }
            }

            if (node->left) {
                S.push(make_pair(node->left, curr));
            }

            if (node->right) {
                S.push(make_pair(node->right, curr));
            }
        }

        return result;
    }
};