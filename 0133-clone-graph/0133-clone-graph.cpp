/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> m;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        m[node]=new Node(node->val);
        for(auto i:node->neighbors)
        {
            if(m.find(i)==m.end())
                m[node]->neighbors.push_back(cloneGraph(i));
            else
                m[node]->neighbors.push_back(m[i]);
        }
        return m[node];
    }
};