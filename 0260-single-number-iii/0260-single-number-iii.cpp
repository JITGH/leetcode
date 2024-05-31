class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        for(auto it:nums){
            if(mpp[it]==1){
                ans.push_back(it);
            }
        }
        return ans;
    }
};