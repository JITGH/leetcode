class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int j=0;j<k;j++){
            freq[nums[j]]++;
        }
        ans.push_back(calXsum(freq,x));

        for(int i=1;i<=n-k;i++){
            freq[nums[i-1]]--;
            if(freq[nums[i-1]]==0){
                freq.erase(nums[i-1]);
            }
            freq[nums[i+k-1]]++;

            ans.push_back(calXsum(freq,x));
        }
        return ans;
    }

    private:
    int calXsum(const unordered_map<int,int>&freq,int x){
        priority_queue<pair<int,int>>pq;
        for(const auto &it:freq){
            pq.push({it.second,it.first});
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