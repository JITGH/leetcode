class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
         int n=nums.size();
        // long long sum=0;
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         sum=nums[i]+nums[j];
        //         if(sum>=lower && sum<=upper){
        //             cnt++;
        //             sum=0;
        //         }else{
        //             sum=0;
        //         }
        //     }
        // }
        // return cnt;

        sort(nums.begin(),nums.end());
        // long long ans=0;
        // for(int i=0;i<n;i++){
        //     int low=lower_bound(nums,i+1,nums.size()-1,lower-nums[i]);

        //     int high=lower_bound(nums,i+1,nums.size()-1,upper-nums[i]+1);

        //     ans+=1LL*(high-low);
        // }
        // return ans;

        return lower_bound(nums,upper+1)-lower_bound(nums,lower);
    }


    // long long lower_bound(vector<int>&nums,int low,int high,int element){
    //     while(low<=high){
    //         int mid=low+(high-low)/2;

    //         if(nums[mid]>=element){
    //             high=mid-1;
    //         }else{
    //             low=mid+1;
    //         }
    //     }
    //     return low;
    // }

     long long lower_bound(vector<int>&nums,int element){
        int left=0;
        int right=nums.size()-1;
        long long result=0;
        while(left<=right){
            int sum=nums[left]+nums[right];

            if(sum<element){
                result+=(right-left);
                left++;
            }else{
                right--;
            }
        }
        return result;

     }
};