class Solution {
// private:
// int f(vector<int>& nums,int n,int k){
//     sort(nums.begin(),nums.end());
//     long long val = nums[0] - k - 1;
//         int c = 0;

//     for(int i=0;i<n;i++){
//         long long curr = nums[i];
//         long long ach=val+1;

//          if (ach < curr - k) {
//                 ach= curr - k;
//             }

//          if (ach <= curr + k) {
//                 c++;
//                 val=ach;
//             }
//     }
//     return c;
// }
public:
    int maxDistinctElements(vector<int>& nums, int k) {
         int n=nums.size();
        // return f(nums,n,k);
        sort(nums.begin(),nums.end());
        int cnt=0;
        int prevMax=INT_MIN;
        for(int i=0;i<n;i++){
            int lower=nums[i]-k;
            int upper=nums[i]+k;

            if(prevMax<lower){
                prevMax=lower;
                cnt++;
            }
            else if(prevMax<upper){
                prevMax++;
                cnt++;
            }
        }
        return cnt;
    }
};