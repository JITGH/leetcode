class Solution {
    private:
    // two pass of sliding window
    // int slidwin(vector<int>& nums, int goal){
    //     int cursum=0;
    //     int cnt=0;
    //     int st=0;
    //     for(int j=0;j<nums.size();j++){
    //         cursum+=nums[j];
    //         while(st<=j && cursum>goal){
    //             cursum-=nums[st++];
    //            // st++;
    //         }
    //         cnt+=(j-st+1);

    //     }
    //     return cnt;
  //  }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //map and track with current sum
        int n=nums.size();
    //    int cnt=0;
    //    int cursum=0;
    //    unordered_map<int,int>mpp;
    //    for(int num:nums){
    //     cursum+=num;
    //     if(cursum==goal){
    //         cnt++;
    //     }
    //     if(mpp.find(cursum-goal)!=mpp.end()){
    //         cnt+=mpp[cursum-goal];
    //     }
    //     mpp[cursum]++;
    //    }
    // return cnt;

    //return slidwin(nums,goal)-slidwin(nums,goal-1);
    int cursum=0;
    int st=0;
    int cnt=0;
    int prefixzeros=0;
    for(int end=0;end<n;end++){
        cursum+=nums[end];

        while(st<end && (nums[st]==0||cursum>goal)){
            if(nums[st]==1){
                prefixzeros=0;
            }else{
                prefixzeros+=1;
            }
            cursum-=nums[st];
            st++;
        }
        if(cursum==goal){
            cnt+=1+prefixzeros;
        }

    }
  return cnt;
    }
};