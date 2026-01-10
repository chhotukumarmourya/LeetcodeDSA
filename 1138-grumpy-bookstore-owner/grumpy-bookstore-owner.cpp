class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int k=minutes;
       int n=customers.size();
       int prevLoss=0;
       for(int i=0;i<k;i++){
         if(grumpy[i]==1){
            prevLoss+=customers[i];
         }
       } 
       int maxLoss=prevLoss;
       int maxIdx=0;
       int j=k;
       int i=1;
       while(j<n){
        int currLoss=prevLoss;
        if(grumpy[j]==1) currLoss+=customers[j];
        if(grumpy[i-1]==1)currLoss-=customers[i-1];
        if(currLoss>maxLoss){
            maxLoss=currLoss;
            maxIdx=i;
        }
        i++;
        j++;
        prevLoss=currLoss;
       }
       for(int i=maxIdx;i<maxIdx+k;i++){
         grumpy[i]=0;
       }
       int sum=0;
       for(int i=0;i<n;i++){
        if(grumpy[i]==0){
            sum+=customers[i];
        }
       }
       return sum;
    }
};