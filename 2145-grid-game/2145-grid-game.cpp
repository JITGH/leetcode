class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long upperScore=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long lowerScore=0;
        long long minSecondRobotPoint=LLONG_MAX;
        for(int col=0;col<grid[0].size();col++){
            upperScore-=grid[0][col];
            minSecondRobotPoint=min(minSecondRobotPoint,max(upperScore,lowerScore));

            lowerScore+=grid[1][col];
        }
        return minSecondRobotPoint;
    }
};