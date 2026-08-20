class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr1;
        vector<int>arr2;
        if(n==0)return nums;
        if(n>=1)arr1.push_back(nums[0]);
        if(n>=2)arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(arr1.back()>arr2.back())arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
         int m=arr2.size();
        for(int i=0;i<m;i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};