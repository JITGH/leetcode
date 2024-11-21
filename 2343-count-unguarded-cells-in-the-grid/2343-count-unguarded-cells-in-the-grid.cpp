class Solution {
    private:
    void makesgaurd(int row,int col,vector<vector<int>>&ans){
        for(int r=row-1;r>=0;r--){//Upwards
            if(ans[r][col]==GUARD||ans[r][col]==WALL) break;
            ans[r][col]=GUARDED;
        }
        for(int r=row+1;r<ans.size();r++){//Downwards
            if(ans[r][col]==GUARD||ans[r][col]==WALL) break;
            ans[r][col]=GUARDED;
        }
        for(int r=col-1;r>=0;r--){//left
            if(ans[row][r]==GUARD||ans[row][r]==WALL) break;
            ans[row][r]=GUARDED;
        }
        for(int r=col+1;r<ans[0].size();r++){//right
            if(ans[row][r]==GUARD||ans[row][r]==WALL) break;
            ans[row][r]=GUARDED;
        }
    }
public:
    const int UNGUARDED=0;
    const int GUARDED=1;
    const int GUARD=2;
    const int WALL=3;
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>ans(m,vector<int>(n,UNGUARDED));
        for(const auto& guard:guards){
            ans[guard[0]][guard[1]]=GUARD;
        }
        for(const auto& wall:walls){
            ans[wall[0]][wall[1]]=WALL;
        }

        for(const auto& guard:guards){
           makesgaurd(guard[0],guard[1],ans);
        }

        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==0) c++;
            }
        }
        return c;
    }
};