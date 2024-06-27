// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         int n=edges.size();
//         int m=edges[0].size();
//         vector<int>ans;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 ans.push_back(edges[i][j]);
//             }
//         }
//         unordered_map<int,int>mpp;
//         for(int i=0;i<ans.size();i++){
//             mpp[ans[i]]++;
//         }
//         for(auto it:mpp){
//             if(it.second==n) return it.first;
//         }
//         return -1;

//     }
// };
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> firstEdge = edges[0];
        vector<int> secondEdge = edges[1];

        return (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1])
                   ? firstEdge[0]
                   : firstEdge[1];
    }
};