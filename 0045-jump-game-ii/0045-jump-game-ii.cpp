class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0;
        int l=0;
        int r=0;
        while(r<n-1){
            jumps++;
            int far=r+1;
            for(int i=l;i<=r;i++){
                if(i+nums[i]>=n-1) return jumps;
                far=max(i+nums[i],far);
            }
            
            l=r+1;
            r=far;
            // jumps++;
        }
        return jumps;
    }
};