class Solution {
public:
vector<vector<long long>>dp;
long long helper(int ind,int row,int n,vector<int>& energyDrinkA, vector<int>& energyDrinkB){
    if(ind>=n) return 0;
    if(dp[ind][row]!=-1) return dp[ind][row];

    long long energy=0;
    if(row==0){
        energy+=energyDrinkA[ind];

    }else{
        energy+=energyDrinkB[ind];
    }

    long long op1=helper(ind+2,!row,n,energyDrinkA,energyDrinkB);
    long long op2=helper(ind+1,row,n,energyDrinkA,energyDrinkB);

    return dp[ind][row]=energy+max(op1,op2);
}

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
       
        int n=energyDrinkA.size();
        dp.resize(n+1,vector<long long>(2,-1));
        return max(helper(0,0,n,energyDrinkA,energyDrinkB),helper(0,1,n,energyDrinkA,energyDrinkB));
    }
};