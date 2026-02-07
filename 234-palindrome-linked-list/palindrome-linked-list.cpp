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
     ListNode*reverse(ListNode*head){
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
    bool isPalindrome(ListNode* head) {
       //ListNode*c=new ListNode(10);
       //ListNode*temp=head;
      // ListNode*tempc=c;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       //c=c->next;
       ListNode*newNode=reverse(slow->next);
      // slow->next=NULL;
       ListNode*a=head;
       ListNode*b=newNode;
       while(b!=NULL){
        if(a->val!=b->val)return false;
        a=a->next;
        b=b->next;
       }
       return true;
    }
};