class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m=target.size();
        int n=words[0].size();
        int mod=1000000007;

        vector<int>dp(m+1,0);
         dp[0]=1;
        vector<vector<int>>seen(n,vector<int>(26,0));
        for(const string& word:words){
            for(int i=0;i<n;i++){
                seen[i][word[i]-'a']++;
            }
        }

       
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                dp[j+1]+=(int)((long)dp[j]*seen[i][target[j]-'a']%mod);
                dp[j+1]%=mod;
            }
        }

        return dp[m];
    }
};