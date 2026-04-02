#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> st;
        int current_result = 0;
        int sign = 1; // 1 for '+', -1 for '-'
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                long long num = 0; // Use long long to prevent overflow during parsing
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                current_result += sign * num;
                i--; // Adjust for the outer loop increment
            } 
            else if (c == '+') {
                sign = 1;
            } 
            else if (c == '-') {
                sign = -1;
            } 
            else if (c == '(') {
                // Push the current result and sign onto the stack
                st.push(current_result);
                st.push(sign);
                // Reset for the new scope inside parentheses
                current_result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                // First pop the sign that was before the '('
                int prev_sign = st.top();
                st.pop();
                // Then pop the result that was before the '('
                int prev_result = st.top();
                st.pop();

                current_result = prev_result + (prev_sign * current_result);
            }
        }
        return current_result;
    }
};