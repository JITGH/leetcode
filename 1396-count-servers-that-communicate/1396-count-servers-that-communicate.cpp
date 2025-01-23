class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int>rowCnt(grid.size(),0);
        vector<int>colCnt(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]) rowCnt[i]++,colCnt[j]++;
            }
        }

        int totalServer=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] &&(rowCnt[i]>1||colCnt[j]>1)) totalServer++;
            }
            }

            return totalServer;
    }
};