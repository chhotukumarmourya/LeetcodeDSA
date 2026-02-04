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
    bool isPalindrome(ListNode* head) {
       ListNode*slow=head;
       ListNode*fast=head;
       while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode*newhead=reverse(slow->next);
       ListNode*a=head;
       ListNode*b=newhead;
       while(b!=NULL){
        if(a->val!=b->val)return false;
        a=a->next;
        b=b->next;
       }
       return true;
    }
};