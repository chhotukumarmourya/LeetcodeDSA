class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int lenA = 0, lenB = 0;

        // Calculate lengths
        while (tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }
        while (tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        // Align both lists
        if (lenA > lenB) {
            int skip = lenA - lenB;
            for (int i = 0; i < skip; i++) {
                tempA = tempA->next;
            }
        } else {
            int skip = lenB - lenA;
            for (int i = 0; i < skip; i++) {
                tempB = tempB->next;
            }
        }

        // Compare nodes
        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA; // or tempB (both same)
    }
};