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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int x=1;
        int f=0;
        ListNode* l=head;
        ListNode* r=head,*p=NULL;
        ListNode* px=NULL;
        while(r)
        {
            if(x==k)
            {
                f++;
                if(f==1)
                    head=r;
                swap(l->next,r->next);
                if(x!=1)
                    r->next=p;
                if(px)
                    px->next=r;
                px=l;
                r=l->next;
                l=r;
                p=l;
                if(r)
                    x=1;
                else
                    x=0;
                continue;
            }
            ListNode* n=r->next;
            r->next=p;
            p=r;
            r=n;
            x++;
        }
        if(x!=0)
        {
            r=p;
            p=NULL;
            while(r!=l)
            {
                ListNode* n=r->next;
                r->next=p;
                p=r;
                r=n;
            }
            ListNode* n=r->next;
            r->next=p;
            p=r;
            r=n;
        }
        return head;
    }
};