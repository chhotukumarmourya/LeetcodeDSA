class Solution {
public:
    int bestClosingTime(string customers) {
      int n=customers.length();
      vector<int>pre(n+1,0);
      vector<int>suf(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+((customers[i]=='N')?1:0);
        }  
        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1]+((customers[i]=='Y')?1:0);
        }
        int minimum=INT_MAX;
        int penality=0;
        for(int i=0;i<=n;i++){
            penality=suf[i]+pre[i];
            minimum=min(minimum,penality);
        }
        for(int i=0;i<=n;i++){
            if(suf[i]+pre[i]==minimum)return i;
        }
        return n;

    }
};