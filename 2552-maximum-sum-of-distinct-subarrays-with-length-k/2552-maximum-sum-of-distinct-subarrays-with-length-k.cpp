class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long cursum=0;
        int i=0;

        unordered_map<int,int>mpp;
       while(i<k && i<nums.size()){
        mpp[nums[i]]++;
        cursum+=nums[i];
        i++;
       }
       if(mpp.size()==k) ans=cursum;
       while(i<nums.size()){
        mpp[nums[i]]++;
        mpp[nums[i-k]]--;
        if(mpp[nums[i-k]]==0) mpp.erase(nums[i-k]);

        cursum+=nums[i];
        cursum-=nums[i-k];
        if(mpp.size()==k) ans=max(ans,cursum);
        i++;
       }
       return ans;
    }
};