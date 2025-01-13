class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int hash[26]={0};
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
            if( hash[s[i]-'a']>=3){
                 hash[s[i]-'a']/=2;
            }
        }
long long sum=0;
        for(int i=0;i<26;i++){
           // cout<<hash[i]<<" ";
            sum+=hash[i];
        }
        return sum;
    }
};