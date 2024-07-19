class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int rminmax=INT_MIN;
        for(int i=0;i<n;i++){
            int rmin=INT_MAX;
            for(int j=0;j<m;j++){
                rmin=min(rmin,matrix[i][j]);
            }
            rminmax=max(rminmax,rmin);
        }
 
        int cminmax=INT_MAX;
        for(int i=0;i<m;i++){
            int cmax=INT_MIN;
            for(int j=0;j<n;j++){
                cmax=max(cmax,matrix[j][i]);
            }
            cminmax=min(cminmax,cmax);
        }

            if(rminmax==cminmax){
                return {rminmax};
            }
            return{};

    }

};