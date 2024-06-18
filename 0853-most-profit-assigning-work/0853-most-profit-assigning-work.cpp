class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>>job;
        for(int i=0;i<n;i++){
            job.push_back({difficulty[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(worker.begin(),worker.end());

        int maxprofit=0;
        int index=0;
        int high=0;
        for(auto it:worker){
        while(index<n && job[index].first<=it){
            high=max(high,job[index].second);
            index++;
        }
        maxprofit+=high;
    }
    return maxprofit;
    }
};