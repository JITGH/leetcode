class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int number=nums[0];
        int cnt=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=number){
                number=nums[i];

            }else{
                cnt++;
            }
        }

        return cnt;

    }
};