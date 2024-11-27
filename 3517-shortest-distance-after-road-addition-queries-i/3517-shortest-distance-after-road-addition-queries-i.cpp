class Solution {
    private:
    int bfs(int n,vector<vector<int>>&adj){
        vector<bool>visit(n,false);
        queue<int>q;
        q.push(0);
        visit[0]=true;
        int curlay=1;
        int next=0;
        int layex=0;
        while(!q.empty()){
            for(int i=0;i<curlay;i++){
                int curr=q.front();
                q.pop();

                if(curr==n-1){
                    return layex;
                }
                for(auto nei:adj[curr]){
                    if(visit[nei]) continue;
                    q.push(nei);
                    next++;
                    visit[nei]=true;
                }
            }

            curlay=next;
            next=0;
            layex++;
        }
        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<vector<int>>adj(n,vector<int>(0));
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(auto& road:queries){
            int u=road[0];
            int v=road[1];
            adj[u].push_back(v);
            ans.push_back(bfs(n,adj));
        }
        return ans;
    }
};