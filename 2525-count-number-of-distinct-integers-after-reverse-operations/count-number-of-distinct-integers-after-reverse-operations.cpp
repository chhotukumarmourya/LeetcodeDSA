class Solution {
public:
    int reverse(int n){
        int sum=0;
        while(n>0){
            sum=sum*10+n%10;
            n=n/10;
        }
        return sum;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
       for(int i=0;i<n;i++){
        s.insert(reverse(nums[i]));
        s.insert(nums[i]);
       } 
       return s.size();
    }
};