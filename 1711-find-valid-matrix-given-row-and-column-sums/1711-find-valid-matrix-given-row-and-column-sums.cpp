class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>>ori(n,vector<int>(m,0));
        int i=0;
        int j=0;
        while(i<n && j<m){
            ori[i][j]=min(rowSum[i],colSum[j]);

            rowSum[i]-=ori[i][j];
            colSum[j]-=ori[i][j];

            rowSum[i]==0?i++:j++;
        }
        return ori;
    }
};