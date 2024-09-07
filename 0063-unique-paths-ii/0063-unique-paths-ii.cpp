class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 ||obstacleGrid[0][0] == 1) return 0;
        
        vector<int> dp(n,0);
        dp[0] = 1;
        for (int i = 0; i <m; i++){
            vector<int>temp(n,0);
            for (int j = 0; j <n; j++){
                if (obstacleGrid[i][j]==1){
                    temp[j]=0;
                    continue;
                } 
                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0){
                    up=dp[j];
                }if(j>0){
                    left=temp[j-1];
                }
                 temp[j] = up + left;
                
            }
            dp=temp;

        }
     return dp[n-1];
    } 
};