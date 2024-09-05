class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
       
        int m=rolls.size();
        int sum=0;
        for(int i:rolls){
            sum+=i;
        }
        int remainsum=(mean*(n+m))-sum;
        if(remainsum>6*n || remainsum<n){
            return {};
        }
        int newmean=remainsum/n;
        int newmod=remainsum%n;
         vector<int>ans(n,newmean);
         for(int i=0;i<newmod;i++){
            ans[i]++;
         }
         return ans;
    }
};