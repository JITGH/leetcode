class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int currCellx=0;
        int currCelly=0;

        while(true){
            vis[currCellx][currCelly]=1;

            int x=currCellx;
            int y=currCelly;

            char move=grid[x][y];

            if(move=='L')y--;
            if(move=='R')y++;
            if(move=='U')x--;
            if(move=='D')x++;

            if(x<0 || x>=n ||y<0||y>=m||vis[x][y]){
                break;
            }

            currCellx=x;
            currCelly=y;
        }

        return {currCellx,currCelly};

    }
};