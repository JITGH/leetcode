class Solution {
public:
const int dirs[3]={-1,0,1};

int dfs(int row,int col,vector<vector<int>>& grid, vector<vector<int>>&dp){
    int n=grid.size();
    int m=grid[0].size();

    if(dp[row][col]!=-1){
        return dp[row][col];
    }

    int maxmove=0;
    for(int dir:dirs){
              int newrow=row+dir;
              int newcol=col+1;

             if(newrow >= 0 && newcol >= 0 && newrow < n && newcol < m &&
                grid[row][col] < grid[newrow][newcol]){
                        maxmove=max(maxmove,1+dfs(newrow,newcol,grid,dp));
                 }

                    
}
return dp[row][col]=maxmove;
}
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

//         queue<vector<int>>q;
//         vector<vector<int>>vis(m,vector<int>(n,0));
//         for(int i=0;i<m;i++){
//             vis[i][0]=1;
//             q.push({i,0,0});
//         }

//         int maxmove=0;
//         while(!q.empty()){
//             int sz=q.size();
//             while(sz--){
//                 vector<int>v=q.front();
//                 q.pop();
//                 int row=v[0];
//                 int col=v[1];
//                 int cnt=v[2];

//                 maxmove=max(maxmove,cnt);

//                 for(int dir:dirs){
//                     int newrow=row+dir;
//                     int newcol=col+1;

//                     if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && 
//                     !vis[newrow][newcol] && grid[row][col]<grid[newrow][newcol]){
//                         vis[newrow][newcol]=1;
//                         q.push({newrow,newcol,cnt+1});
//                     }
//                 }
//             }
//         }
// return maxmove;

        vector<vector<int>>dp(m,vector<int>(n,-1));

        int maxmove=0;
        for(int i=0;i<m;i++){
            int movesRequired=dfs(i,0,grid,dp);

            maxmove=max(maxmove,movesRequired);
        }
        return maxmove;
    }
};