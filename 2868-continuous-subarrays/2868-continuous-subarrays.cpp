class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
       map<int,int>freq;
       int left=0;
       int right=0;
       int n=nums.size();
       long long cnt=0,windowLen=0;
       int curMin,curMax;
    
    //    while(right<n){
    //     freq[nums[right]]++;

    //     while(freq.rbegin()->first-freq.begin()->first>2){
    //         freq[nums[left]]--;
    //         if(freq[nums[left]]==0){
    //             freq.erase(nums[left]);
    //         }
    //         left++;
    //     }
    //     count+=right-left+1;
    //     right++;
    //    }
    // priority_queue<int,vector<int>,function<bool(int,int)>>minheap(
    //     [&nums](int a,int b) {return nums[a]>nums[b]; });
    // priority_queue<int,vector<int>,function<bool(int,int)>>maxheap(
    //     [&nums](int a,int b) {return nums[a]<nums[b];});

    //     while(right<n){
    //         minheap.push(right);
    //         maxheap.push(right);

    //         while(left<right && nums[maxheap.top()]-nums[minheap.top()]>2){
    //             left++;
            
    //         while(!maxheap.empty() && maxheap.top()<left){
    //             maxheap.pop();
    //         }
    //          while(!minheap.empty() && minheap.top()<left){
    //             minheap.pop();
    //         }
    //     }
    //         count+=right-left+1;
    //         right++;
    //     }

        curMin=curMax=nums[right];
        for(right=0;right<n;right++){
            curMin=min(curMin,nums[right]);
            curMax=max(curMax,nums[right]);

            if(curMax-curMin>2){
                windowLen=right-left;
                cnt+=(windowLen*(windowLen+1)/2);


                left=right;
                curMin=curMax=nums[right];

                while(left>0 && abs(nums[right]-nums[left-1])<=2){
                    left--;
                    curMin=min(curMin,nums[left]);
                    curMax=max(curMax,nums[left]);

                }
                if(left<right){
                    windowLen=right-left;
                   cnt-=(windowLen*(windowLen+1)/2);
                }
            }
        }
        windowLen=right-left;
        cnt+=(windowLen*(windowLen+1)/2);

       return cnt;
    }
};