// class Solution {
// public:
//     int minimumTime(vector<vector<int>>& grid) {
//         if(grid[0][1]>1 && grid[1][0]>1) return -1;


//         int n=grid.size();
//         int m=grid[0].size();

//         vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
//         vector<vector<bool>>visit(n,vector<bool>(m,false));

//         priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
//         pq.push({grid[0][0], 0, 0});

//         while(!pq.empty()){
//             auto cur=pq.top();
//             pq.pop();
//             int t=cur[0];
//             int row=cur[1];
//             int col=cur[2];

//             if(row==n-1 && col==m-1){
//                 return t;
//             }
//             if(visit[row][col]) continue;
//             visit[row][col]=true;
//             for(auto &d:dir){
//                 int nrow=row+d[0];
//                 int ncol=col+d[1];
//                 if(!isvalid(visit,nrow,ncol)){
//                     continue;
//                 }
//             int waittime=((grid[nrow][ncol]-t)%2==0)?1:0;
//             int nt= max(grid[nrow][ncol] + waittime, t + 1);

//             pq.push({nt,nrow,ncol});

//             }
//         }
//         return -1;
//     }
// private:
//     bool isvalid(vector<vector<bool>>& visit, int row, int col){
//         return row>=0 && col>=0 && row<visit.size() && col<visit[0].size() && !visit[row][col];
//     }
// };

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        const vector<pair<int,int>> DIRS = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        
        int rows = grid.size(), cols = grid[0].size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        
        pq.push({0, 0, 0}); // (time, row, col)
        seen[0][0] = true;
        
        while (!pq.empty()) {
            auto [time, row, col] = pq.top();
            pq.pop();
            
            for (const auto& [dr, dc] : DIRS) {
                int newRow = row + dr;
                int newCol = col + dc;
                
                if (newRow < 0 || newRow >= rows || 
                    newCol < 0 || newCol >= cols || 
                    seen[newRow][newCol]) {
                    continue;
                }
                
                int newTime = time + 1;
                if (grid[newRow][newCol] > newTime) {
                    newTime += ((grid[newRow][newCol] - time) / 2) * 2;
                }
                
                if (newRow == rows - 1 && newCol == cols - 1) {
                    return newTime;
                }
                
                seen[newRow][newCol] = true;
                pq.push({newTime, newRow, newCol});
            }
        }
        
        return -1;
    }
};