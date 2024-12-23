class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxi(prices,0);
    }

    private:
    int maxi(vector<int>& prices,int st){

        int profit=0;
        for(int i=st;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]>prices[i]){
                    int pro=prices[j]-prices[i]+maxi(prices,j+1);

                    profit=max(profit,pro);
                }
            }
        }
        return profit;
    }
};