class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> gr(numCourses);
        for (const auto& edge : prerequisites) {
            gr[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        vector<unordered_set<int>> precomp(numCourses);

        while (!q.empty()) {
           int it = q.front();
            q.pop();
            for (int adj : gr[it]) {
                precomp[adj].insert(it);
                for (int pre : precomp[it]) {
                    precomp[adj].insert(pre);
                }
                if (--indeg[adj] == 0)
                    q.push(adj);
            }
        }
        vector<bool> ans;
        for (const auto& q : queries) {
            ans.push_back(precomp[q[1]].count(q[0]));
        }
        return ans;
    }
};