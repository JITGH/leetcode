class Solution {
    private:
    int f(vector<int>& ans, int k){
         if(k<0) return 0;
        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        int n=ans.size();
        while(r<n){
            sum=sum+ans[r];
            while(sum>k){
                sum=sum-ans[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>ans;
        for(int num:nums){
            if(num%2==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }
        }
        return f(ans,k)-f(ans,k-1);
    }
};