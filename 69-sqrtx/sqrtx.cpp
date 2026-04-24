class Solution {
public:
    int mySqrt(int x) {
        int lo=0;
        int high=x/2;
        if(x<=4){
            high=x;
        }
        while(lo<=high){
            long long mid=lo+(high-lo)/2;
            if(mid*mid==x){
               return mid; 
            }else if(mid*mid>x){
                high=mid-1;
            }else{
              lo=mid+1;
            }
        }
      return high;
    }
};