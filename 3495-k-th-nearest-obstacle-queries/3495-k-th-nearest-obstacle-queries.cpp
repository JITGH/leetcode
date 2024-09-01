class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n=queries.size();
        vector<int>ans;
        priority_queue<int>pq;
        for(auto &it:queries){
            int a=it[0];
            int b=it[1];

            int tot=abs(a)+abs(b);

            if(pq.size()<k){
                pq.push(tot);
            }else if(pq.top()>tot){
                pq.pop();
                pq.push(tot);
            }
            
            if(pq.size()<k){
            ans.push_back(-1);
        }else {
            ans.push_back(pq.top());
           // pq.pop();
        }
        }
        
       return ans;
    }
};