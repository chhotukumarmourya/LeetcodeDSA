class Solution {
public:
    long long power(long long x, int k, long long limit){
        long long res = 1;
        for(int i = 0; i < k; i++){
            res *= x;
            if(res > limit) return limit + 1;
        }
        return res;
    }

    // Largest x such that x^k <= r
    int mySqrt(int r, int k) {
        int lo = 0;
        int high = r;
        while(lo <= high){
            long long mid = lo + (high - lo) / 2;
            long long p = power(mid, k, r);
            if(p <= r) lo = mid + 1;
            else       high = mid - 1;
        }
        return high;  // largest x where x^k <= r
    }

    // Smallest x such that x^k >= l
    int mySqrt2(int l, int k) {
        int lo = 0;
        int high = l;
        while(lo <= high){
            long long mid = lo + (high - lo) / 2;
            long long p = power(mid, k, l);
            if(p >= l) high = mid - 1;
            else       lo = mid + 1;
        }
        return lo;  // smallest x where x^k >= l
    }

    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1;
        int R = mySqrt(r, k);   // largest x where x^k <= r
        int L = mySqrt2(l, k);  // smallest x where x^k >= l
        return R - L + 1;
    }
};