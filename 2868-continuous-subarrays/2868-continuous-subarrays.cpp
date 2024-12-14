class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
       map<int,int>freq;
       int left=0;
       int right=0;
       int n=nums.size();
       long long count=0;
    
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
    priority_queue<int,vector<int>,function<bool(int,int)>>minheap(
        [&nums](int a,int b) {return nums[a]>nums[b]; });
    priority_queue<int,vector<int>,function<bool(int,int)>>maxheap(
        [&nums](int a,int b) {return nums[a]<nums[b];});

        while(right<n){
            minheap.push(right);
            maxheap.push(right);

            while(left<right && nums[maxheap.top()]-nums[minheap.top()]>2){
                left++;
            
            while(!maxheap.empty() && maxheap.top()<left){
                maxheap.pop();
            }
             while(!minheap.empty() && minheap.top()<left){
                minheap.pop();
            }
        }
            count+=right-left+1;
            right++;
        }
       return count;
    }
};