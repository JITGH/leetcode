class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // bool flag=false;
        // for(int i=0;i<nums.size()-1;i++){
            
        //         if(nums[i]==nums[i+1]){
        //             flag=true;
        //         }
            
        // }
        // // return flag;
        // unordered_map<int,int>mpp;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        // for(int n:nums){
        //     if(mpp[n]>=2) return true;
        // }
        // return false;

        unordered_set<int>st(nums.begin(),nums.end());
        return nums.size()>st.size();
        
    }
};