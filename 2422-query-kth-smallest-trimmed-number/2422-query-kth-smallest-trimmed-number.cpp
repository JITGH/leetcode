class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &i : queries) {
            vector<string> temp = nums;
            
            for(int j = 0; j < temp.size() ; j++) {
                temp[j] = temp[j].substr(temp[j].size() - i[1]);
                
            }
            
            
            vector<pair<string, int>> vp;
            
            for(int j =0 ;j < temp.size() ; j++) {
                vp.push_back({temp[j] , j});
            }
            
            
            sort(vp.begin() , vp.end(), [&](const pair<string, int> &a , const pair<string,int> &b){
                if(a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });
            
            
            ans.push_back(vp[i[0] - 1].second);
        }
        
        return ans;
    }
};