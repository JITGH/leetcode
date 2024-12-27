class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
         int n=values.size();
        // int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(((values[i]+values[j])+(i-j))>maxi) maxi=(values[i]+values[j])+(i-j);
        //     }
        // }

        // return maxi;

        int leftmaxScore=values[0];
        int maxScore=0;
        for(int i=1;i<n;i++){
            maxScore=max(maxScore,leftmaxScore+values[i]-i);
            leftmaxScore=max(leftmaxScore,values[i]+i);
        }
        return maxScore;
    }
};