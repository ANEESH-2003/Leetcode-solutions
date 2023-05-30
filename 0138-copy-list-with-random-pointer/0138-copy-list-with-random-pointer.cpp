/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node* a=head;
        while(head)
        {
            m[head]=new Node(head->val);
            head=head->next;
        }
        head=a;
        while(head)
        {
            m[head]->next=m[head->next];
            m[head]->random=m[head->random];
            head=head->next;
        }
        head=a;
        return m[head];
    }
};