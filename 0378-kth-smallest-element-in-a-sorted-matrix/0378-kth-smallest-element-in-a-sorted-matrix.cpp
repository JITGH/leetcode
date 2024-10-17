class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        priority_queue<int>maxHeap;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                maxHeap.push(matrix[r][c]);
                if(maxHeap.size()>k) maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};