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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(head==NULL || left==right)return head; 
       ListNode*temp=head;
       ListNode*a=NULL;
      ListNode*b=NULL;
      ListNode*c=NULL;
      ListNode*d=NULL;
       int n=1;
       while(temp!=NULL){
         if(left-1==n)a=temp;
         if(left==n)b=temp;
         if(right==n)c=temp;
         if(right+1==n)d=temp;
         temp=temp->next;
         n++;
       } 
       c->next=NULL;
       ListNode*rev=reverse(b);
       if(a!=NULL)a->next=rev;
       b->next=d;
       if(left==1)return rev;
       return head;
    }
};