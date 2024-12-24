class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //       //  for(int k=j+1;k<n;k++){
        //             if(nums[i]<nums[j] && nums[j]<nums[j+1]){
        //                 return true;
        //             }
        //       //  }
        //     }
        // }
        // return false;

        int first=INT_MAX;
        int second=INT_MAX;
        for(int num:nums){
            if(num<=first){
                first=num;
            }
           else if(num<=second){
                second=num;
            }else{
                return true;
            }
        }
        return false;
    }
};