class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrValue=0;
        for(int num:nums){
            maxOrValue|=num;
        }
        return countSubsets(nums,0,0,maxOrValue);
    }

    private:
    int countSubsets(vector<int>& nums,int ind,int currentOr,int targetOr){
        if(ind==nums.size()){
            return (currentOr==targetOr)?1:0;

        }
        int countwithOut=countSubsets(nums,ind+1,currentOr,targetOr);
        int countwith=countSubsets(nums,ind+1,currentOr|nums[ind],targetOr);

        return countwithOut+countwith;
    }
};