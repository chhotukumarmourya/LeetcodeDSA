class Solution {
public:
    int digitFrequencyScore(int n) {
        // unordered_map<int, int> mp;
        // string s = to_string(n);
        // for (char c : s) {
        //     mp[c - '0']++;
        // }
        // int sum = 0;
        // for (auto it : mp) {
        //     sum += it.first * it.second;
        // }

        // return sum;
        int sum = 0;
        while (n > 0) {
           sum=sum+n%10;
           n=n/10;
        }
        return sum;
    }
};