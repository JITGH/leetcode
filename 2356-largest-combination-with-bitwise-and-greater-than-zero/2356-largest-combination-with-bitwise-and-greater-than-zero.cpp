class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        int maxand=0;
        for(int i=0;i<24;i++){
            int c=0;
            for(int num:candidates){
                if((num&(1<<i))!=0){
                    c++;
                }
            }
            maxand=max(maxand,c);
        }
        return maxand;
    }
};