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
  ListNode * func(ListNode * &head , int length)
                {
                  if(head == NULL)
                    return NULL ;

                   ListNode *dumyhead = new ListNode(head->val) ;
                   head = head->next ;
                   ListNode *ptr = dumyhead ;
              
                   int cnt = 1 ;

                   while( ( cnt < length ) && ( head != NULL ) )
                      {
                         ListNode *p = new ListNode(head->val);
                         ptr->next = p ;
                         ptr = p ;

                         head = head->next ;

                         cnt++ ;
                      }

                     return dumyhead ;
                }
         
    int list_size(ListNode *ptr)
               {
                 int cnt = 0 ;
                 while(ptr)
                    {
                       cnt++ ;
                       ptr = ptr->next ;
                    }
                  return cnt ;
               }
   
  vector<ListNode*> splitListToParts(ListNode* head, int k)
   {
       int size = list_size(head);
       
       int length = size/k ;
       int rem = size%k ;

       vector<ListNode *> v ;

       while(k--)
         {
            int len ;
            if(rem != 0)
              {
                 len = length  + 1 ;
                 rem-- ;
              }
            else{
                len = length ;
            }

            ListNode *start = func(head , len) ;

            v.push_back(start) ;
         }
         
         return v ;
    }
};