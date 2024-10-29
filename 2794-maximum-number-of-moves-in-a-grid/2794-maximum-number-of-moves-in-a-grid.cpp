class Solution {
public:
const int dirs[3]={-1,0,1};
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<vector<int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            vis[i][0]=1;
            q.push({i,0,0});
        }

        int maxmove=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                vector<int>v=q.front();
                q.pop();
                int row=v[0];
                int col=v[1];
                int cnt=v[2];

                maxmove=max(maxmove,cnt);

                for(int dir:dirs){
                    int newrow=row+dir;
                    int newcol=col+1;

                    if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && 
                    !vis[newrow][newcol] && grid[row][col]<grid[newrow][newcol]){
                        vis[newrow][newcol]=1;
                        q.push({newrow,newcol,cnt+1});
                    }
                }
            }
        }
return maxmove;
    }
};