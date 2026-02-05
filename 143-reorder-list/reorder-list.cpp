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
     ListNode* reverse(ListNode* head) {
       ListNode*prev=NULL;
       ListNode*current=head;
       ListNode*Next=head;
       while(current!=NULL){
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
       } 
       return prev;
     }

    void reorderList(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*temp=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*a=head;
       ListNode*b=reverse(slow->next);
       slow->next=NULL;
       ListNode*c=new ListNode(10);
       ListNode*tempc=c;
       ListNode*tempb=b;
       ListNode*tempa=a;
       while(tempa!=NULL && tempb!=NULL ){
           tempc->next=tempa;
           tempa=tempa->next;
           tempc=tempc->next;
           tempc->next=tempb;
           tempb=tempb->next;
           tempc=tempc->next;
       }
       //if(tempa)
       tempc->next=tempa;
       head=c->next;
    }
};