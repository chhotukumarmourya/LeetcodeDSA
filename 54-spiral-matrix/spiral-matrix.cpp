class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        int minr=0;
        int minc=0;
        int maxr=m-1;
        int maxc=n-1;
        while(minc<=maxc && minr<=maxr){
            for(int j=minc;j<=maxc;j++){
                ans.push_back(matrix[minr][j]);
            }
            minr++;
            for(int i=minr;i<=maxr;i++){
                ans.push_back(matrix[i][maxc]);
            }
            maxc--;
            if(minr<=maxr){
                for(int j=maxc;j>=minc;j--){
                    ans.push_back(matrix[maxr][j]);
                }
            }
            maxr--;
            if(minc<=maxc){
                for(int i=maxr;i>=minr;i-- ){
                    ans.push_back(matrix[i][minc]);
                }
            }
            minc++;
        }
        return ans;
    }
};