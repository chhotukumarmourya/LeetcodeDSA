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
    ListNode* partition(ListNode* head, int x) {
        ListNode*dummy1=new ListNode(200);
        ListNode*dummy2=new ListNode(200);
        ListNode*lo=dummy1;
        ListNode*hi=dummy2;
        ListNode*temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                 lo->next=temp;
                 temp=temp->next;
                 lo=lo->next;
            }else{
                hi->next=temp;
                temp=temp->next;
                hi=hi->next;
            }
        }
        lo->next=dummy2->next;
        hi->next=NULL;
        return dummy1->next;
    }
};