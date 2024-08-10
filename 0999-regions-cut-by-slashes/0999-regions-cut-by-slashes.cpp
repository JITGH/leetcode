class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>>a(grid.size()*3,vector<int>(grid.size()*3));
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int br=i*3;
                int bc=j*3;

                if(grid[i][j]=='\\'){
                    a[br][bc]=1;
                    a[br+1][bc+1]=1;
                    a[br+2][bc+2]=1;
                }else if(grid[i][j]=='/'){
                    a[br][bc+2]=1;
                    a[br+1][bc+1]=1;
                    a[br+2][bc]=1;
                }
            }
        }

        int regionc=0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(a[i][j]==0){
                    floodfill(a,i,j);
                    regionc++;
                }
            }
        }
        return regionc;
    }


    private:
    void floodfill(vector<vector<int>>&a,int i,int j){
        const vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        a[i][j]=1;
        q.push({i,j});
        while(!q.empty()){
            auto cr=q.front().first;
            auto cc=q.front().second;
            q.pop();

            for(auto &it:dir){
                int nr=it[0]+cr;
                int nc=it[1]+cc;
                if(isvalid(a,nr,nc)){
                    a[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }

    bool isvalid(vector<vector<int>>&a,int nr,int nc){
        return nr>=0 && nr<a.size() && nc>=0 && nc<a.size() && a[nr][nc]==0;
    }
};