class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=*max_element(candies.begin(),candies.end());
        vector<bool>ans;
        for(int i=0;i<candies.size();i++){
          if(maxi<=candies[i]+extraCandies){
            ans.push_back(true);
            //maxi=candies[i]+extraCandies;
          }
          else{
            ans.push_back(false);
          }
          
        }
        return ans;
    }
};