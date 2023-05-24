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
    bool isPalindrome(ListNode* head) {
        int n=0;
        ListNode* x=head;
        while(x)
        {
            n++;
            x=x->next;
        }
        ListNode* a=head,*b=head,*p=NULL;
        int c=0;
        while(c!=n/2)
        {
            c++;
            x=a->next;
            a->next=p;
            p=a;
            a=x;
        }
        if(n%2)
        {
            a=a->next;
        }
        b=a;
        while(p && b)
        {
            if(b->val!=p->val)
            {
                return 0;
            }
            b=b->next;
            p=p->next;
        }
        return 1;
    }
};