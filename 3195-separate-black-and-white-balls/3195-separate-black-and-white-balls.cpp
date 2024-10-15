class Solution {
public:
    long long minimumSteps(string s) {
        long long int cnt=0;
        long long ans=0;
        int n=s.size();
        int i=0;
        for(;i<n;i++){
            if(s[i]=='0'){
                ans+=i-cnt;

                cnt++;
            }
        }
        return ans;
    }
};