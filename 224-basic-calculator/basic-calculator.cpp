class Solution {
public:
    int calculate(string s) {
        int result = 0;      // current result
        int sign = 1;        // current sign: 1 for '+', -1 for '-'
        stack<int> st;       // stack for parentheses: stores (result_before, sign_before)
        
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            char ch = s[i];
            
            if (ch == ' ') {
                i++;
            } 
            else if (ch == '+') {
                sign = 1;
                i++;
            } 
            else if (ch == '-') {
                sign = -1;
                i++;
            } 
            else if (ch == '(') {
                // push current result and sign onto stack
                st.push(result);
                st.push(sign);
                // reset for new sub-expression
                result = 0;
                sign = 1;
                i++;
            } 
            else if (ch == ')') {
                // pop saved sign and previous result
                int prev_sign = st.top(); st.pop();
                int prev_result = st.top(); st.pop();
                // combine: prev_result + prev_sign * (current result)
                result = prev_result + prev_sign * result;
                i++;
            } 
            else { // digit
                // parse the whole number
                long long num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
            }
        }
        
        return result;
    }
};