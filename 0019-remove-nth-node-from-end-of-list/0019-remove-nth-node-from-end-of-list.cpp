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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=new ListNode(0,head);
        ListNode* f=p;
        int l=1;
        ListNode* c=head;
        while(c->next)
        {
            c=c->next;
            l++;
            if(l==n+1)
            {
                p=p->next;
                l--;
            }
        }
        p->next=p->next->next;
        return f->next;
    }
};