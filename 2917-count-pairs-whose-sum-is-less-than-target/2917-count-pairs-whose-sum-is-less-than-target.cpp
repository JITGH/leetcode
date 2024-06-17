// class Solution {
// public:
//     int countPairs(vector<int>& nums, int target) {
//         int n=nums.size();
//         int c=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]+nums[j]<target) c++;
//             }
//         }
//         return c;
//     }
// };

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
     
    sort(nums.begin(), nums.end());
            int ans = 0;
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l < h) {
        if (nums[l] + nums[h] < target) {
            ans += h - l;
            l++;
        } else {
            h--;
        }
    }
    
    return ans;
    }
};