class Solution {
    private:
    int timer=1;
 
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                // node --- it
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, 
    vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections){
           int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
            int tm[n];
            int low[n];
            vector<int>vis(n,0);
            vector<vector<int>>bridge;
            dfs(0,-1,vis,adj,tm,low,bridge);


        return bridge;
    }
};