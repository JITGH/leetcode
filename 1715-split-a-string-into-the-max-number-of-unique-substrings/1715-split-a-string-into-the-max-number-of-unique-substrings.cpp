class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>seen;
        int maxc=0;
        backtrack(s,0,seen,0,maxc);
        return maxc;
    }
    private:
    void backtrack(string s,int start,unordered_set<string>&seen,int cnt,int &maxc){
        if(cnt+(s.size()-start)<=maxc) return;
        if(start==s.size()){
            maxc=max(maxc,cnt);
            return;
        }
     
        for(int end=start+1;end<=s.size();end++){
            string substring=s.substr(start,end-start);
            if(seen.find(substring)==seen.end()){
                seen.insert(substring);
                backtrack(s,end,seen,1+cnt,maxc);
                seen.erase(substring);
            }
        }
     
    }
};