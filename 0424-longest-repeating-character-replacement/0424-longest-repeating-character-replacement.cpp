class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
      int  hash[26]={0};
        int maxl=0;
        int maxf=0;
        while(r<n){

           hash[s[r]-'A']++;
           maxf=max(maxf,hash[s[r]-'A']);

           if((r-l+1)-maxf>k){
             hash[s[l]-'A']--;
             //maxf=0;
             l=l+1;
           }
           if((r-l+1)-maxf<=k){
            maxl=max(maxl,r-l+1);
           }
           r++;
    }
    return maxl;
    }
};