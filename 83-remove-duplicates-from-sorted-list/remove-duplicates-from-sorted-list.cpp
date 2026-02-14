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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode*a=head;
        ListNode*b=head->next;
        ListNode* newHead = new ListNode(head->val);
        ListNode* c = newHead;
        while(b!=NULL ){
            if(b->val==a->val){
                b=b->next;
            }else{
                ListNode*t=new ListNode(b->val);
                
                c->next=t;
                c=t;
                a=b;
                
                b=b->next;
            }
        }
        return newHead;
    }
};