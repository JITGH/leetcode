class Solution {
    const int MOD=1e9+7;
    private:
    // int f(int ind,int target,vector<int>& nums,vector<vector<int>>&dp){
    //     if(ind==0){
    //         if(target==0 && nums[0]==0) return 2;
    //         if(target==0||nums[0]==target) return 1;

    //         return 0;
    //     }
    //     if(dp[ind][target]!=-1) return dp[ind][target];
    //     int nottake=f(ind-1,target,nums,dp);

    //     int take=0;
    //     if(nums[ind]<=target)
    //     take=f(ind-1,target-nums[ind],nums,dp);

    //     return dp[ind][target]=(take+nottake);
    // }

    int f(vector<int>& nums, int t){
          int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(t+1,0));
       
         if(nums[0]==0) dp[0][0]=2;
         else dp[0][0]=1;

         if(nums[0]!=0 && nums[0]<=t) dp[0][nums[0]]=1;

         for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=t;tar++){
                int nottake=dp[ind-1][tar];

                int take=0;
                if(nums[ind]<=tar)
                take=dp[ind-1][tar-nums[ind]];


                dp[ind][tar]=(take+nottake)%MOD;
            }
         }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=t;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        //  }
         return dp[n-1][t];

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }

        if(totalSum-target<0 ||(totalSum-target)%2!=0) return 0;
        // if((totalSum-target)%2==1) return 0;

      //  int secondOp=;
       // vector<vector<int>>dp(n,vector<int>(secondOp+1,-1));
        return f(nums,(totalSum-target)/2);
    }
};