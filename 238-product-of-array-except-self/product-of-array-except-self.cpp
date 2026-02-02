class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m=nums.size();
        vector<int>prefix(m);
        int p=nums[0];
        prefix[0]=1;
        for(int i=1;i<m;i++){
            prefix[i]=p;
            p*=nums[i];
        }
        p=nums[m-1];
        for(int i=m-2;i>=0;i--){
            prefix[i]*=p;
            p*=nums[i];
        }
        return prefix;
    }
};