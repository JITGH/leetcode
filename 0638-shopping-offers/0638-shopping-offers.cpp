// class Solution {
// private:
//     int ex(int ind, vector<int> ds, vector<int> &price, vector<vector<int>> &offer, vector<int> &need,  map<int,map<vector<int>,int>> &dp){
//         if(ind==offer.size()){
//             int tot=0;
//             for(int i=0; i<need.size(); i++){
//                 tot+=(need[i]-ds[i])*price[i];
//             }
//             return tot;
//         }
        
//         if(dp.find(ind)!=dp.end() && dp[ind].find(ds)!=dp[ind].end()){
//             return dp[ind][ds];
//         }

//         int offer_notTake=ex(ind+1,ds,price,offer,need,dp);

//         int offer_take=1e9;
//         vector<int> copyDS=ds;

//         for(int i=0; i<need.size(); i++){
//             if(copyDS[i]+offer[ind][i]<=need[i]){
//                 copyDS[i]+=offer[ind][i];
//             }else{
//                 return dp[ind][ds]=min(offer_notTake,offer_take);
//             }
//         }
//         offer_take=offer[ind][price.size()]+ex(ind,copyDS,price,offer,need,dp);

//         return dp[ind][ds]=min(offer_notTake,offer_take); 
//     }

// public:
//     int shoppingOffers(vector<int>& price, vector<vector<int>>& offer, vector<int>& need) {
//         map<int,map<vector<int>,int>> dp;
//         vector<int> ds(need.size(),0);
//         return ex(0,ds,price,offer,need,dp);
//     }
// };



class Solution {
public:
    map<vector<int>, int> mp;
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs){
        int n = price.size();
        int cost = INT_MAX;
        vector<int> v = needs;

        if(mp.find(needs) != mp.end())return mp[needs];

        for(int i = 0; i < special.size(); i++){
            bool flag = true;
            int totalPrice = 0;
            for(int j = 0; j < n; j++){
                if(special[i][j] > needs[j]) flag= false;
                totalPrice += (price[j] * needs[j]);
            }

            if(flag && totalPrice > special[i][n]){
                for(int j = 0; j < n; j++){
                    v[j] = needs[j] - special[i][j];
                }
                cost = min(cost, special[i][n] + solve(price, special, v));
            }
        }

        if(cost == INT_MAX){
            cost = 0;
            for(int i = 0; i < n; i++){
                cost += price[i]*needs[i];
            }
        }

        return mp[needs] = cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int cost = 0, n = price.size();
        for(int i = 0; i < n; i++){
            cost += (price[i]*needs[i]);
        }
        cost = min(cost, solve(price, special, needs));
        return cost;
    }

};