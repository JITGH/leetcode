class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int ss=0,ds=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<10) ss+=nums[i];
            else ds+=nums[i];
        }

        if(ss==ds) return false;
        return true;
    }
};