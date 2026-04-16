/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode*tempA=headA;
      ListNode*tempB=headB;
      int lA=0;
      int lB=0;
      while(tempA!=NULL){
        lA++;
        tempA=tempA->next;
      }
      while(tempB!=NULL){
        lB++;
        tempB=tempB->next;
      }
      tempA=headA;
      tempB=headB;
      if(lA>lB){
        int idx=lA-lB;
        for(int i=1;i<idx+1;i++){
            tempA=tempA->next;
        }while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
      }else{
        int idx=lB-lA;
        for(int i=1;i<idx+1;i++){
            tempB=tempB->next;
        }
        while(tempB!=tempA){
           tempA=tempA->next;
            tempB=tempB->next; 
        }
        return tempA;
      }
    }
};