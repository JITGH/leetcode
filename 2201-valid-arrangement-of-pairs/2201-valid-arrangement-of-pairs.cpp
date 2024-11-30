// class Solution {
// public:
//     vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
//         unordered_map<int, deque<int>> adjacencyMatrix;
//         unordered_map<int, int> inDegree, outDegree;

//         // Build the adjacency list and track in-degrees and out-degrees
//         for (const auto& pair : pairs) {
//             int start = pair[0], end = pair[1];
//             adjacencyMatrix[start].push_back(end);
//             outDegree[start]++;
//             inDegree[end]++;
//         }

//         vector<int> result;

//         // Helper lambda function for DFS traversal,
//         // you can make a seperate private function also
//         function<void(int)> visit = [&](int node) {
//             while (!adjacencyMatrix[node].empty()) {
//                 int nextNode = adjacencyMatrix[node].front();
//                 adjacencyMatrix[node].pop_front();
//                 visit(nextNode);
//             }
//             result.push_back(node);
//         };

//         // Find the start node (outDegree == 1 + inDegree )
//         int startNode = -1;
//         for (const auto& entry : outDegree) {
//             int node = entry.first;
//             if (outDegree[node] == inDegree[node] + 1) {
//                 startNode = node;
//                 break;
//             }
//         }

//         // If no such node exists, start from the first pair's first element
//         if (startNode == -1) {
//             startNode = pairs[0][0];
//         }

//         // Start DFS traversal
//         visit(startNode);

//         // Reverse the result since DFS gives us the path in reverse
//         reverse(result.begin(), result.end());

//         // Construct the result pairs
//         vector<vector<int>> pairedResult;
//         for (int i = 1; i < result.size(); ++i) {
//             pairedResult.push_back({result[i - 1], result[i]});
//         }

//         return pairedResult;
//     }
// };

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<int, int> inOutDegree;
        
        // Build graph and count in/out degrees
        for (const auto& pair : pairs) {
            adjacencyList[pair[0]].push_back(pair[1]);
            inOutDegree[pair[0]]++;  // out-degree
            inOutDegree[pair[1]]--;  // in-degree
        }
        
        // Find starting node (head)
        int startNode = pairs[0][0];
        for (const auto& [node, degree] : inOutDegree) {
            if (degree == 1) {
                startNode = node;
                break;
            }
        }
        
        vector<int> path;
        stack<int> nodeStack;
        nodeStack.push(startNode);
        
        while (!nodeStack.empty()) {
            auto& neighbors = adjacencyList[nodeStack.top()];
            if (neighbors.empty()) {
                path.push_back(nodeStack.top());
                nodeStack.pop();
            } else {
                int nextNode = neighbors.back();
                nodeStack.push(nextNode);
                neighbors.pop_back();
            }
        }
        
        vector<vector<int>> arrangement;
        int pathSize = path.size();
        arrangement.reserve(pathSize - 1);
        
        for (int i = pathSize - 1; i > 0; --i) {
            arrangement.push_back({path[i], path[i-1]});
        }
        
        return arrangement;
    }
};
