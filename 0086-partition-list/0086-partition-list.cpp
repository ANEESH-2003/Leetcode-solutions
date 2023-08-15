/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* c=head;
        ListNode* p=NULL;
        while(c)
        {
            ListNode* t=c,*pt=p;
            while(pt && pt->val>=x && t->val<x)
            {
                swap(pt->val,t->val);
                t=pt;
                pt=pt->next;
            }
            t=c->next;
            c->next=p;
            p=c;
            c=t;
        }
        while(p)
        {
            ListNode* t=p->next;
            p->next=c;
            c=p;
            p=t;
        }
        return c;
    }
};