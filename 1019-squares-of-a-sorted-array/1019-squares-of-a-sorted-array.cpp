class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        long long n;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            n=(long long)nums[i]*(long long)nums[i];
            ans.push_back(n);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};