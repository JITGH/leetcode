class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long tot=0;
        int minabsval=INT_MAX;
        int negcnt=0;
        for(auto& row:matrix){
            for(int val:row){
                tot+=abs(val);
                if(val<0){
                    negcnt++;
                }
                minabsval=min(minabsval,abs(val));
            }

        }
        if(negcnt%2!=0){
            tot-=2*minabsval;
        }
        return tot;
    }
};