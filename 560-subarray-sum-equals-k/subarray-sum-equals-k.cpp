class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<int>pre(n,0);
        // pre[0]=nums[0];
        unordered_map<int,int>mp;
        // for(int i=1;i<n;i++){
        //     pre[i]=nums[i]+pre[i-1];
        // }
       
        int pre=0;
        int count=0;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            if(pre==k){
                count++;
            }
            int rem=pre-k;
            if(mp.find(rem)!=mp.end()){
                count=count+mp[rem];

            }
            mp[pre]++;
        }
        return count;
    }
};