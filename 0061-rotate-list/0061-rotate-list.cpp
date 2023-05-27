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
    int n=0;
    ListNode* rev(ListNode* head)
    {
        ListNode* a=head,*b=NULL;
        while(a)
        {
            n++;
            ListNode* c=a->next;
            a->next=b;
            b=a;
            a=c;
        }
        return b;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        n=0;
        ListNode* x=rev(head);
        if(n<=1)
            return head;
        k%=n;
        int g=k;
        ListNode* a=x,*b=NULL;
        while(k--)
        {
            ListNode* c=a->next;
            a->next=b;
            b=a;
            a=c;
        }
        if(g)
        {
            x->next=head;
            head=b;
        }
        b=NULL;
        while(a)
        {
            ListNode* c=a->next;
            a->next=b;
            b=a;
            a=c;
        }
        return head;
    }
};