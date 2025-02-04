class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s=original.size();
        if(m*n!=original.size()){
            return vector<vector<int>>(0,vector<int>(0));
        }
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<s;i++){
            ans[i/n][i%n]=original[i];
        }
        return ans;


    }
};