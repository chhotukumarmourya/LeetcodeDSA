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
ListNode* merge(ListNode* list1, ListNode* list2) {
       ListNode*a=list1;
       ListNode*b=list2;
       ListNode* dummy = new ListNode(100);
      ListNode* c = dummy;
      while(a!=NULL && b!=NULL){
        if(a->val<=b->val){
            ListNode*t=new ListNode(a->val);
            c->next=t;
            c=t;
          
            a=a->next;
        }else{
            ListNode*t=new ListNode(b->val);
            c->next=t;
            //b=b->next->next;
            c=t;
            b=b->next;
        }
      }
      if(a==NULL){
        c->next=b;
      }else{
        c->next=a;
      }
      return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
      ListNode*slow=head;
      ListNode*fast=head;
       if(head==NULL ||head->next==NULL)return head;
      while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
      } 
      ListNode*a=head;
      ListNode*b=slow->next; 
      slow->next=NULL;
      a=sortList(a);
      b=sortList(b);
      ListNode*c=merge(a,b);
      return c;
    }
};