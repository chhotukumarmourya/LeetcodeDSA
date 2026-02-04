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
        ListNode*c=new ListNode(10);
        ListNode*temp=head;
        ListNode*tempc=c;
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