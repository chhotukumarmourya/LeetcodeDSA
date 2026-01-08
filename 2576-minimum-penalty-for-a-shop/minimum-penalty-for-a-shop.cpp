class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        vector<int> pre(n + 1, 0);
        vector<int> suf(n + 1, 0);

        // prefix: N before i
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (customers[i] == 'N');
        }

        // suffix: Y after i
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + (customers[i] == 'Y');
        }

        int minPenalty = INT_MAX;
        int res = 0;

        for (int i = 0; i <= n; i++) {
            int penalty = pre[i] + suf[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                res = i;
            }
        }

        return res;
    }
};
