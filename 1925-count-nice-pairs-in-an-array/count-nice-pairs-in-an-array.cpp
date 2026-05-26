class Solution {
public:
    int rev(int x){
        int y=0;
        while(0<x){
            y=y*10+x%10;
            x/=10;
        }
        return y;
    }
    
   
    int countNicePairs(vector<int>& nums) {
    int n=nums.size();
     int count=0;
     unordered_map<int,int>m;
     for(int i=0;i<n;i++){
        nums[i]=nums[i]-rev(nums[i]);
     }   
    for(int i=0;i<n;i++){
       if(m.find(nums[i])!=m.end(nums[i])){
        count=count%1000000007;
        count+=m[nums[i]];
       }
       m[nums[i]]++;
    }
    
    return count%1000000007;
    }
};