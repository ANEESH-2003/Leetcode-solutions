/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* a=head,*b=head;
        while(b && b->next)
        {
            a=a->next;
            b=b->next->next;
            if(a==b)
                break;
        }
        if(!(b && b->next))
            return NULL;
        while(a!=head)
        {
            a=a->next;
            head=head->next;
        }
        return a;
    }
};