class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
     /*   vector<int>tmp(nums.size());
        for(int i=0;i<nums.size();i++){
            tmp[(i+k)%nums.size()]=nums[i];
        }
        //copy temp into nums vector
       nums=tmp;
       */
           k = k%nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin()+k);
        // reverse(nums.begin()+k, nums.end());

        auto reverse = [&](int start, int end) {
            while (start < end) {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
        };
        
        reverse(0, n - 1);  // Reverse the whole array
        reverse(0, k - 1);  // Reverse the first k elements
        reverse(k, n - 1);  // Reverse the rest
    }
};