class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
           priority_queue<int> pq;
           for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);

           }
      

        
           while(k--){
            int it=pq.top();
            pq.pop();
            int sq=floor(sqrt(it));
           // cout<<sq<<" ";
            pq.push(sq);
           }

          long long ans=0;
           while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
           }
           
           return ans;
    }
};