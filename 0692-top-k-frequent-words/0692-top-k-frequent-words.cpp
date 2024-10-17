class Solution {
    struct Comp{
        bool operator()(const pair<int,string>&a,const pair<int,string>&b){
            if(a.first!=b.first) return a.first<b.first;
            return a.second>b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mpp;
        for(string s:words){
            mpp[s]++;
        }

       priority_queue<pair<int,string>,vector<pair<int,string>>,Comp>pq;
       for(auto it:mpp){

        pq.push({it.second,it.first});
       }
       while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
       }
       return ans;

    }
};