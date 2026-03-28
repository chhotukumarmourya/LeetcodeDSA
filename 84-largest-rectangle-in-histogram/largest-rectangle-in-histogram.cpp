class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> nsi(n), psi(n);
        
        // NSI
        stack<int> st;
        nsi[n-1] = n;
        st.push(n-1);
        
        for(int i = n-2; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(st.empty()) nsi[i] = n;
            else nsi[i] = st.top();
            
            st.push(i);
        }
        
        // PSI
        stack<int> gt;
        psi[0] = -1;
        gt.push(0);
        
        for(int i = 1; i < n; i++) {
            while(!gt.empty() && arr[gt.top()] >= arr[i]) {
                gt.pop();
            }
            if(gt.empty()) psi[i] = -1;
            else psi[i] = gt.top();
            
            gt.push(i);
        }
        
        // Area
        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
            int height = arr[i];
            int width = nsi[i] - psi[i] - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};