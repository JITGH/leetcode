class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int>bmx(26,0);
        for(const string& b:words2){
            vector<int>bcnt=ispre(b);
        
        for(int i=0;i<26;i++){
            bmx[i]=max(bcnt[i],bmx[i]);
        }
        }
        vector<string>ans;
        for(const string& a:words1){
            vector<int>acnt=ispre(a);
            bool issub=true;
            for(int i=0;i<26;i++){
                if(bmx[i]>acnt[i]){
                    issub=false;
                    break;
                }
            }
            if(issub) ans.push_back(a);
        }
return ans;
    }

    private:
    vector<int> ispre(const string &s){
       vector<int>ans(26,0);
       for(char c:s){
        ans[c-'a']++;
       }
       return ans;
    }
};