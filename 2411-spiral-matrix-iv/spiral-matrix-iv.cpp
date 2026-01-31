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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode*temp=head;
        int maxc=n-1;
        int maxr=m-1;
        int minc=0;
        int minr=0;
        vector<vector<int>>arr(m,vector<int>(n,-1));
        while(minc<=maxc && minr<=maxr){
            for(int i=minc;i<=maxc;i++){
                if(temp==NULL)return arr;
                arr[minr][i]=temp->val;
                temp=temp->next;
            }
            minr++;
            for(int j=minr;j<=maxr;j++){
                if(temp==NULL)return arr;
                arr[j][maxc]=temp->val;
                temp=temp->next;
            }
            maxc--;
            if(minr<=maxr){
                for(int i=maxc;i>=minc;i--){
                    if(temp==NULL)return arr;
                    arr[maxr][i]=temp->val;
                    temp=temp->next;
                }
            }
            maxr--;
            if(minc<=maxc){
                for(int j=maxr;j>=minr;j--){
                    if(temp==NULL)return arr;
                    arr[j][minc]=temp->val;
                    temp=temp->next;
                }
            }
            minc++;
        }
        return arr;
    }
};