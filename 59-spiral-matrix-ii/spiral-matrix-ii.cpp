class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        int m=N;
        int n=N;
        vector<vector<int>> mat(N, vector<int>(N));
        int minr=0;
        int minc=0;
        int maxr=m-1;
        int maxc=n-1;
        int cout=1;
        while(minc<=maxc && minr<=maxr){
            for(int j=minc;j<=maxc;j++){
               mat[minr][j]=cout++;
            }
            minr++;
            for(int i=minr;i<=maxr;i++){
                mat[i][maxc]=cout++;
            }
            maxc--;
            if(minr<=maxr){
                for(int j=maxc;j>=minc;j--){
                    mat[maxr][j]=cout++;
                }
            }
            maxr--;
            if(minc<=maxc){
                for(int i=maxr;i>=minr;i-- ){
                    mat[i][minc]=cout++;
                }
            }
            minc++;
        }
        return mat;

    }
};