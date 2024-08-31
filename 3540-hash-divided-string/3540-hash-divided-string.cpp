class Solution {
public:
    string stringHash(string s, int k) {
        int i=0;
        string res;
        int n=s.size();
        for(int i=0;i<n;i+=k){
            int tot=0;
            for(int j=i;j<i+k;j++){
                tot+=s[j]-'a';
            }

            int ans=tot%26;
            char c='a'+ans;
            res+=c;
        }
return res;
    }
};