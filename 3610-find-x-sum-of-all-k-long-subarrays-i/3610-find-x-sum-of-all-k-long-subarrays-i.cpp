class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;

        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int j=0;j<k;j++){
            mpp[nums[j]]++;
        }
        ans.push_back(calxsum(mpp,x));

        for(int i=1;i<=n-k;i++){
            mpp[nums[i-1]]--;
            if(mpp[nums[i-1]]==0){
                mpp.erase(nums[i-1]);
            }
            mpp[nums[i+k-1]]++;
            ans.push_back(calxsum(mpp,x));
        }

        return ans;
    }

    private:
    int calxsum(const unordered_map<int,int>&mpp,int x){
        priority_queue<pair<int,int>>pq;

        for(const auto& entry:mpp){
            pq.push({entry.second,entry.first});
        }
        int sum=0;
        for(int i=0;i<x && !pq.empty();i++){
            auto top=pq.top();
            pq.pop();
            sum+=top.second*top.first;
        }
        return sum;
    }
};