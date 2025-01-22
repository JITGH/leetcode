class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>height(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
         vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

         for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(isWater[r][c]==1){
                    height[r][c]=0;
                    q.push({r,c});
                }
            }
         }

         while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(const auto&d:dir){
                int nr=r+d[0];
                int nc=c+d[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && height[nr][nc]==-1){
                    height[nr][nc]=height[r][c]+1;
                    q.push({nr,nc});
                }
            }
         }
         return height;
    }
};