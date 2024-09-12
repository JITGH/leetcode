class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(int i=0;i<allowed.size();i++){
            st.insert(allowed[i]);
        }
        int cnt=0;
        for(string & it:words){
            bool iscon=true;;
            for(int i=0;i<it.size();i++){
                char cur=it[i];
                if(st.find(cur)==st.end()){
                    iscon=false;
                    break;
                }
            }

            if(iscon){
                cnt++;
            }
        }
return cnt;
    }
};