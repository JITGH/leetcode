class Solution {
    private:
    int f(int ind,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0||nums[0]==target) return 1;

            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake=f(ind-1,target,nums,dp);

        int take=0;
        if(nums[ind]<=target)
        take=f(ind-1,target-nums[ind],nums,dp);

        return dp[ind][target]=(take+nottake);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }

        if(totalSum-target<0) return 0;
        if((totalSum-target)%2==1) return 0;

        int secondOp=(totalSum-target)/2;
        vector<vector<int>>dp(n,vector<int>(secondOp+1,-1));
        return f(n-1,secondOp,nums,dp);
    }
};