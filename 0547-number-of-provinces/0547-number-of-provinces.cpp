class DisjointSet {
    vector<int> rank, parent,size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    //By rank

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    
    //By size 
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};



class Solution {
    // private:
    // void dfs(int node,vector<int>adj[],vector<bool>&visited){
    //     visited[node]=1;
    //     for(auto it: adj[node]){
    //         if(!visited[it]){
    //             dfs(it,adj,visited);
    //         }
    //     }
    // }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n=isConnected.size();
        // vector<int>adj[n];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1 && i!=j){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }

        // vector<bool>visited(n);
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(!visited[i]){
        //         cnt++;
        //         dfs(i,adj,visited);
        //     }
        // }
        // return cnt;

        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i){
                cnt++;
            }
        }
        return cnt;
    }
};