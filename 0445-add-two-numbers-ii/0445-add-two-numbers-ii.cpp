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
private: 
    void reverseList(ListNode* &head){
    
        ListNode* current = head;
        ListNode* prev = NULL;

        while(current!=NULL){
            ListNode* temp = current->next;
            current->next = prev;

            prev = current;
            current = temp;
        }

        head = prev;

    }

    void insert(ListNode* head, int data){
        ListNode* node = new ListNode(data);
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reversing lists
        reverseList(l1);
        reverseList(l2);

        //creating new Node
        ListNode* newNode = new ListNode();
        ListNode* head = newNode;

        //initialising pointers
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->val + temp2->val + carry;
            
            insert(head, (sum%10));
            carry = sum/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1!=NULL){
            int sum = temp1->val + carry;
            insert(head, (sum%10));
            carry = sum/10;
            temp1 = temp1->next;
        }

        while(temp2!=NULL){
            int sum = temp2->val + carry;
            insert(head, (sum%10));
            carry = sum/10;
            temp2 = temp2->next;
        }

        if(carry>0){
            insert(head, carry);
        }

        head = head->next;
        reverseList(head);

        return head;
    }
};