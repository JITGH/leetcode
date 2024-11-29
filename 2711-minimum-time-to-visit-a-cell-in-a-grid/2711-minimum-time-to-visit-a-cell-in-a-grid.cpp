class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1) return -1;


        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>>visit(n,vector<bool>(m,false));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int t=cur[0];
            int row=cur[1];
            int col=cur[2];

            if(row==n-1 && col==m-1){
                return t;
            }
            if(visit[row][col]) continue;
            visit[row][col]=true;
            for(auto &d:dir){
                int nrow=row+d[0];
                int ncol=col+d[1];
                if(!isvalid(visit,nrow,ncol)){
                    continue;
                }
            int waittime=((grid[nrow][ncol]-t)%2==0)?1:0;
            int nt= max(grid[nrow][ncol] + waittime, t + 1);

            pq.push({nt,nrow,ncol});

            }
        }
        return -1;
    }
private:
    bool isvalid(vector<vector<bool>>& visit, int row, int col){
        return row>=0 && col>=0 && row<visit.size() && col<visit[0].size() && !visit[row][col];
    }
};