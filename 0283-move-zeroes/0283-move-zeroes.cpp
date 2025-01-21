class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastZeroFound=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[lastZeroFound++]=nums[i];
            }
        }

        for(int i=lastZeroFound;i<nums.size();i++){
            nums[i]=0;
        }
    }
};