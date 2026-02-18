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
        ListNode*curr=head;
        ListNode*Next=head;
        while(curr!=NULL){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
     }
    bool isPalindrome(ListNode* head) {
        ListNode*c=new ListNode(100);
        ListNode*tempc=c;
        ListNode*temp=head;
        while(temp!=NULL){
           ListNode*t=new ListNode(temp->val);
           tempc->next=t;
           temp=temp->next;
           tempc=tempc->next;
        }
        c=c->next;
        c=reverse(c);
        ListNode*a=head;
        ListNode*b=c;
        while(a!=NULL){
            if(a->val!=b->val)return false;
            a=a->next;
            b=b->next;
        }
        return true;
    }
};