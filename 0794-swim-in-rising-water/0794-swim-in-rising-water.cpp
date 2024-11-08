class DisjointSet
{
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1); // to take care of 1-based indexing as well
        parent.resize(n + 1);  // to take care of 1-based indexing as well
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        int up_u = findParent(u);
        int up_v = findParent(v);
        if (up_u == up_v)
            return;
        if (size[up_u] > size[up_v])
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
        else
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // unordered_map<int,pair<int,int>> ump;
         int n = grid.size();
         if(n==1) return 0;
        // DisjointSet ds(n*n);
        // for(int i = 0; i<n; i++)
        //     for(int j = 0; j<n; j++)
        //         ump[grid[i][j]]={i,j};
        // int time = 0;
        // while(ds.findParent(0)!=ds.findParent(n*n - 1))
        // {
        //     auto node = ump[time];
        //     int x = node.first;
        //     int y = node.second;
        //     int dx[] = {-1,0,1,0};
        //     int dy[] = {0,-1,0,1};
        //     for(int i = 0; i<4; i++)
        //     {
        //         int nrow = x + dx[i];
        //         int ncol = y + dy[i];
        //         if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]<=time)
        //             ds.unionBySize(nrow*n + ncol,x*n + y);
        //     }
        //     time++;
        // }
        // return time-1;

        vector<vector<bool>>visited(n,vector<bool>(n));
        visited[0][0]=true;
        int result=max(grid[0][0],grid[n-1][n-1]);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({result,0,0});
        while(!pq.empty()){
            vector<int>curr=pq.top();
            pq.pop();

            result=max(result,curr[0]);
            for(int i=0;i<4;i++){
                int x=curr[1]+dir[i][0];
                int y=curr[2]+dir[i][1];

                if(x<0 || x>=n ||y<0 ||y>=n || visited[x][y]){
                    continue;
                }
                if(x==n-1 && y==n-1){
                    return result;
                }

                pq.push({grid[x][y],x,y});
                visited[x][y]=true;
            }
        }
        return -1;
        
    }

    private:
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
};