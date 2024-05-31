class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        for(auto it:nums){
            if(mpp[it]==1){
                return it;
            }
        }
        return -1;
    }
};