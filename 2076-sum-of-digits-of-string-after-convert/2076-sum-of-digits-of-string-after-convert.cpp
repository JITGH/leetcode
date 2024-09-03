class Solution {
public:

    int getLucky(string s, int k) {
        int n=s.size();
        string ans="";
        for(char ch:s){
            ans+=to_string(ch-'a'+1);
        }
        
        while(k-->0){
            int tot=0;
            for(char it:ans){
                tot+=it-'0';
            }
            ans=to_string(tot);
        }
        return stoi(ans);
    }
};