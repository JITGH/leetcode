class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>st(bannedWords.begin(),bannedWords.end());
        int c=0;
        for(string s:message){
            if(st.find(s)!=st.end()){
                c++;
                if(c>=2){
                    return true;
                }
            }
        }
        return false;
    }
};