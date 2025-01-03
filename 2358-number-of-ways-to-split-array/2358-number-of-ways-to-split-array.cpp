class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        //int sum1=0;
        vector<long long>preSum(n);
        preSum[0]=nums[0];

        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i];
        }

        for(int i=0;i<n-1;i++){
            long long leftSum=preSum[i];
            long long rightSum=preSum[n-1]-preSum[i];

            if(leftSum>=rightSum){
                c++;
            }
        }
return c;





        // for(int i=0;i<n-1;i++){
        //     sum1+=nums[i];
        //     int sum2=0;
        //     for(int j=i+1;j<n;j++){
        //         sum2+=nums[j];
        //     }
        //     if(sum1>=sum2){
        //         c++;
        //     }
        // }
        // return c;
    }
};