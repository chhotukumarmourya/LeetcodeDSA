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
        int lenA=0;
        int lenB=0;
         while(tempA!=NULL){
            lenA++;
            tempA=tempA->next;
            
         }
         while(tempB!=NULL){
            lenB++;
            tempB=tempB->next;
            
         }
         tempA=headA;
         tempB=headB;
         if(lenA>lenB){
            int skip=lenA-lenB;
            for(int i=0;i<skip;i++){
                 tempA=tempA->next;
            }
         }else{
            int skip=lenB-lenA;
            for(int i=0;i<skip;i++){
                tempB=tempB->next;
            }
         }
         while(tempA !=NULL && tempB!=NULL){
            if(tempA==tempB)return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
         }
         return NULL;

    }
};