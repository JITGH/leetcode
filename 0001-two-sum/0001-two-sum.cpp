class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum=0;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
           

            if((mpp.find(target - nums[i])!=mpp.end())&&(i!=mpp[target-nums[i]])){
                return {i,mpp[target-nums[i]]};
            }
             mpp[nums[i]]=i;
        }

        return {-1,-1};
    }
};