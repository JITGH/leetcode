// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//     //     sort(nums.begin(),nums.end());
//     //     //int i=0;
//     //    int duplicate=0;
//     //     for(int k=0;k<nums.size();k++)
//     //        // int j=k+1;
//     //     if(nums[k]==nums[k+1]){
// //           // int c=k;
// //          // return nums[k];
// //          duplicate=nums[k];
// //          break;
// //     }
// //    // return c;
// //         return duplicate ;

// unordered_map<int,int>m;
// int n=nums.size();

// for(int i=0;i<n;i++){
//     m[nums[i]]++;
// }

// for(auto it:m){
//     if(it.second>=2){
//         return it.first;
//     }
// }
// return -1;
//     }
//    // return nums[k];
//      //return duplicate ;
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};