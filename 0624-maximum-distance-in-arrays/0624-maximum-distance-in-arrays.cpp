class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        int maxd=0;
        int n=arrays.size();
     
        for(int i=1;i<n;i++){
           // for(int j=0;j<m;j++){
            maxd=max(maxd,abs(arrays[i].back()-mini));
            maxd=max(maxd,abs(arrays[i][0]-maxi));
                maxi=max(maxi,arrays[i].back());
                mini=min(mini,arrays[i][0]);
           // }
        }

        return maxd;
    }
};