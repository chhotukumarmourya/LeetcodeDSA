class Solution {
public:
     vector<int>ans;
     int climbStairs(int n) {
        ans.resize(n+1, -1);
        return stair(n);
     }
     int stair(int x){
        if(x==1)return 1;
        if(x==2)return 2;
        if(ans[x]!=-1)return ans[x];
        return ans[x]=stair(x-1)+stair(x-2);
     }
};