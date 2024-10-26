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
    struct height_less {
        bool operator()(pair<int, int> left, pair<int, int> right) {
            if (left.first == right.first) {
                return left.second < right.second;
            }
            return left.first < right.first;
        }
    };

    using HeightPriorityQueue =
        priority_queue<pair<int, int>, vector<pair<int, int>>, height_less>;

    int collect_heights(TreeNode* root, int level,
                 unordered_map<int, HeightPriorityQueue>& level_heights,
                 unordered_map<int, int>& node_level) {
        if (root == nullptr) {
            return 0;
        }

        int left_h = collect_heights(root->left, level + 1, level_heights, node_level);
        int right_h = collect_heights(root->right, level + 1, level_heights, node_level);
        int curr_h = max(left_h, right_h);

        node_level[root->val] = level;
        level_heights[level].push({curr_h, root->val});

        return curr_h + 1;
    }

    int
    heightWithoutNode(int value,
                      unordered_map<int, HeightPriorityQueue>& level_heights,
                      unordered_map<int, int>& node_level) {
        auto it = node_level.find(value);
        assert(it != node_level.end());

        int level = it->second;

        auto& level_q = level_heights[level];

        auto max_height = level_q.top();
        if (max_height.second == value) {
            if (level_q.size() == 1) {
                return level - 1;
            }

            level_q.pop();
            int result = level + level_q.top().first;
            level_q.push(max_height);
            return result;
        }

        return level + max_height.first;
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> result;

        unordered_map<int, HeightPriorityQueue> level_heights;
        unordered_map<int, int> node_level;

        collect_heights(root, 0, level_heights, node_level);

        for (int q : queries) {
            int height = heightWithoutNode(q, level_heights, node_level);
            result.push_back(height);
        }

        return result;
    }
};