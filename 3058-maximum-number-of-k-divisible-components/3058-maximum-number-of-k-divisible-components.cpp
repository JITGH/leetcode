// class Solution {
// public:
//     int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
//           vector<vector<int>>gr(n);
//         vector<int>indegre(n);
//         vector<long long>nodevalue(values.begin(),values.end());
//         if(n==1) return 1;
//         for(const auto& it:edges){
//             int u=it[0];
//             int v=it[1];
//             gr[u].push_back(v);
//             gr[v].push_back(u);
//             indegre[u]++;
//             indegre[v]++;
//         }

//         queue<int>q;
//         for(int i=0;i<n;i++){
//             if(indegre[i]==1) q.push(i);
//         }

//         int compcnt=0;
//         while(!q.empty()){
//             auto it=q.front();
//             q.pop();
//             indegre[it]--;
//             int addval=(nodevalue[it]%k==0)?0:nodevalue[it];
//             if(addval==0) compcnt++;
//             for(auto neigh:gr[it]){
//                 if(indegre[neigh]>0){
//                     indegre[neigh]--;
//                     nodevalue[neigh]+=addval;
//                     if(indegre[neigh]==1) q.push(neigh);
//                 }

//             }
//         }
//         return compcnt++;
//     }
// };

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (auto neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k;  // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0) componentCount++;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
};