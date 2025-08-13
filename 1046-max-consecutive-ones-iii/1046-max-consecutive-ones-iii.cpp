class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxl=0;
        int z=0;
        int n = nums.size();

        while(r<n){
            if(nums[r]==0) z++;

            if(z>k){
                if(nums[l]==0) z--;
                l++;
            }
            if(z<=k){
                maxl=max(maxl,r-l+1);
                
            }
            r++;
        }
        return maxl;
    }
};