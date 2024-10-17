class Solution {
    private:
    int  getdistance(vector<int>&point){
        return point[0]*point[0]+point[1]*point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>>maxHeap;
        for(vector<int>&point:points){
            maxHeap.push({getdistance(point),point});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};