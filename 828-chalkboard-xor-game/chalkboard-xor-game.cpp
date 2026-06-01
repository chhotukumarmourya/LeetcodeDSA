class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n=nums.size();
        if(n%2==0){
            return true;
        }else{
            int x=0;
            for(int i=0;i<n;i++){
                x^=nums[i];
            }
            if(x==0){
                return true;
            }else{
                return false;
            }
        }
    }
};