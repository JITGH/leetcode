class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(string& word:words){
            cnt+=hasPrefix(word,pref);
        }
        return cnt;
    }


    private:
    int hasPrefix(string& str,string& pref){
        int itr;

        for(itr=0;itr<str.size()&&itr<pref.size();itr++){
            if(str[itr]!=pref[itr]){
                return 0;
            }
        }

        if(itr!=pref.size()){
            return 0;
        }

        return 1;
    }
};