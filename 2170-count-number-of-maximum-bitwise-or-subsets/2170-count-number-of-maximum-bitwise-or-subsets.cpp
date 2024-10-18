class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxOrValue=0;
        for(int num:nums){
            maxOrValue|=num;
        }
        vector<vector<int>>memo(n,vector<int>(maxOrValue+1,-1));
        return countSubsets(nums,0,0,maxOrValue,memo);
    }

    private:
    int countSubsets(vector<int>& nums,int ind,int currentOr,int targetOr,vector<vector<int>>&memo){
        if(ind==nums.size()){
            return (currentOr==targetOr)?1:0;

        }
        if(memo[ind][currentOr]!=-1) return memo[ind][currentOr];
        int countwithOut=countSubsets(nums,ind+1,currentOr,targetOr,memo);
        int countwith=countSubsets(nums,ind+1,currentOr|nums[ind],targetOr,memo);

        return countwithOut+countwith;
    }
};