class Solution {
   
public:
    static bool sortele(pair<int, int> &a, pair<int, int>& b)
{
  if (a.second == b.second)
    return a.first > b.first;
  return a.second < b.second;
}

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        vector<pair<int,int>>ret;
        for(auto it:mpp){
            ret.push_back(it);
        }

        sort(ret.begin(),ret.end(),sortele);
        vector<int>ans;
        for(int i=0;i<ret.size();i++){
            while(ret[i].second>0){
                ans.push_back(ret[i].first);
                ret[i].second--;
            }
        }

        return ans;
    }
};