class Solution {
public:
    bool isSubsequence(string s, string t) {
        int c=0;
        for(int j=0;j<t.size();j++){
            if(s[c]==t[j]){
                c++;
            }
        }
        return c==s.size();
    }
};