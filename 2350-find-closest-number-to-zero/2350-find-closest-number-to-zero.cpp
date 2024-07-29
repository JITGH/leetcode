class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int n=nums.size();
        for(int i:nums){
         //   int diff=abs(nums[i]-0);
         if(abs(i)<abs(mini)){
             mini=i;
         }
    else if(abs(mini)==abs(i)){
        mini=max(mini,i);
    }
            
            
        }
        return mini;
    }
};