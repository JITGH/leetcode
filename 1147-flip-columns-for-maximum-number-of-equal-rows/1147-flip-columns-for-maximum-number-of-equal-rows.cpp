class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mpp;
        for(auto &currentRow:matrix){
            string patternBuilder="";
            for(int col=0;col<currentRow.size();col++){
                if(currentRow[0]==currentRow[col]){
                    patternBuilder+="T";
                }else{
                     patternBuilder+="F";
                }
            }
            mpp[patternBuilder]++;
        }
        int maxi=0;
        for(auto& entry:mpp){
            maxi=max(maxi,entry.second);
        }

        return maxi;
    }
};