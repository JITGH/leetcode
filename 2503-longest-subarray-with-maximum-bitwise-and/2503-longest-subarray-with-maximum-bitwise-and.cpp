class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int maxi=0;
        int cur=0;
        for(int num:nums){
            if(maxi<num){
                maxi=num;
                ans=cur=0;
            }
            if(maxi==num){
                cur++;
            }else{
                cur=0;
            }
            ans=max(ans,cur);
        }
       
        return ans;
    }
};