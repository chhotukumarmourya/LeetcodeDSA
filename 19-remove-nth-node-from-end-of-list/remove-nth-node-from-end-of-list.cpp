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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int le=0;
        ListNode*temp=head;
        while(temp!=NULL){
            le++;
            temp=temp->next;
        }
        if(le==n){
            head=head->next;
            return head;
        }
        int m=le-n;
       // int idx=m-1;
        temp=head;
        for(int i=1;i<=m-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};