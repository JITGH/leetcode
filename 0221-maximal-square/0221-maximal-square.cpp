class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<vector<int>>dp(rows+1,vector<int>(cols+1,0));
        int maxi=0;
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    int right=dp[i][j+1],dia=dp[i+1][j+1],bottom=dp[i+1][j];
                    dp[i][j]=1+min(right,min(dia,bottom));
                    maxi=max(maxi,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return maxi*maxi;
    }
};