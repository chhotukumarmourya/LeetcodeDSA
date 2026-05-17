class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        // For k == 1, every integer in the range is a perfect 1st power.
        if (k == 1) {
            return r - l + 1;
        }
        
        long long count = 0;
        // Include 0 if it lies in the range.
        if (l == 0) {
            count = 1;
        }
        
        // Iterate over positive bases.
        for (long long x = 1; ; ++x) {
            long long power = 1;
            bool overflow = false;
            // Compute x^k safely, checking overflow against r.
            for (int i = 0; i < k; ++i) {
                if (power > r / x) {
                    overflow = true;
                    break;
                }
                power *= x;
            }
            if (overflow) {
                break; // All larger x will also exceed r.
            }
            if (power >= l) {
                ++count;
            }
        }
        return (int)count;
    }
};