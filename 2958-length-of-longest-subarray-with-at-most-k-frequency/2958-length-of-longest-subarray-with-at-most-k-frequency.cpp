class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int start=-1;
        unordered_map<int,int>mpp;
        for(int end=0;end<nums.size();end++){
            mpp[nums[end]]++;
            while(mpp[nums[end]]>k){
                start++;
                mpp[nums[start]]--;
            }
            ans=max(ans,end-start);
        }
        return ans;
    

    }
};