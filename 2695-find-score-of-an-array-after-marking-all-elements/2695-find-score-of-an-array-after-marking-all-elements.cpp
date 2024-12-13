class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        vector<bool>marked(nums.size());
        auto cmp=[](pair<int,int>&pair1,pair<int,int>&pair2){
            if(pair1.first!=pair2.first) return pair1.first>pair2.first;
            return pair1.second>pair2.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq(cmp);
        for(int i=0;i<nums.size();i++){
            pq.push(make_pair(nums[i],i));
        }

        while(!pq.empty()){
            pair<int,int>it=pq.top();
            pq.pop();
            int num=it.first;
            int ind=it.second;

            if(!marked[ind]){
                ans+=num;
                marked[ind]=true;
            
            if(ind-1>=0){
                marked[ind-1]=true;
            }
            if(ind+1<nums.size()){
                marked[ind+1]=true;
            }
        }
        }
        return ans;
    }
};