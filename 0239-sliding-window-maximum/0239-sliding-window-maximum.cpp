class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //   vector<int>ans;
    //   deque<int>dq;
    //   for(int i=0;i<nums.size();i++){
    //       if(!dq.empty()&& dq.front()==i-k) dq.pop_front();
    //       while(!dq.empty()&& nums[i]>=nums[dq.back()])
    //       dq.pop_back();
    //       dq.push_back(i);
    //       if(i>=k-1) ans.push_back(nums[dq.front()]);
    //   }  
    //   return ans;
    vector<int>ans;
    priority_queue<pair<int,int>>pq;
    if(k==0) return ans;
    for(int i=0,n=nums.size();i<n;i++){
        while(!pq.empty() && pq.top().second<=i-k)
        pq.pop();
        pq.push(make_pair(nums[i],i));
        if(i>=k-1)
        ans.push_back(pq.top().first);
    }
    return ans;
    }
};