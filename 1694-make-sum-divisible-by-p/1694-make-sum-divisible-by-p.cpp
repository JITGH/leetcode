class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int totsum=0;

        for(int i=0;i<n;i++){
            totsum=(totsum+nums[i])%p;
        }

        int target=totsum%p;
        if(target==0) return 0;

        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int cursum=0;
        int minlen=n;
        for(int i=0;i<n;i++){
        cursum=(cursum+nums[i])%p;
        int need=(cursum-target+p)%p;

        if(mpp.find(need)!=mpp.end()){
            minlen=min(minlen,i-mpp[need]);
        }

        mpp[cursum]=i;
        }

        return minlen==n?-1:minlen;
    }
};