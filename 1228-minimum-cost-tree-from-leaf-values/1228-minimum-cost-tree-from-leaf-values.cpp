class Solution {
public:
int find_max(int l,int h,vector<int>&arr){
    int maxi=0;
    for(int i=l;i<=h;i++){
        maxi=max(arr[i],maxi);
    }
    return maxi;
}
int fun(int l,int h,vector<int>&arr,vector<vector<int>>&dp){
    if(l==h) return dp[l][h]=0;
    if(h-l==1) return dp[l][h]=arr[l]*arr[h];

    int ans=INT_MAX,a,b,temp;
    if(dp[l][h]!=-1)
    return dp[l][h];
    for(int i=l;i<h;i++){
        a=find_max(l,i,arr);
        b=find_max(i+1,h,arr);
        temp=fun(l,i,arr,dp)+fun(i+1,h,arr,dp);
        ans=min(ans,(a*b)+temp);
    }
    return dp[l][h]=ans;
}
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(0,n-1,arr,dp);
    }
};