class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int cnt=1;
        for(int lay=0;lay<(n+1)/2;lay++){
            for(int i=lay;i<n-lay;i++){
                ans[lay][i]=cnt++;
            }
            for(int i=lay+1;i<n-lay;i++){
                ans[i][n-lay-1]=cnt++;
            }
            for(int i=n-lay-2;i>=lay;i--){
                ans[n-lay-1][i]=cnt++;
            }for(int i=n-lay-2;i>lay;i--){
                ans[i][lay]=cnt++;
            }
        }
        return ans;
    }
};