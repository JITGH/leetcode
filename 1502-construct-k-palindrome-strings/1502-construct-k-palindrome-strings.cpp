class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        if(s.size()==k) return true;
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int cnt=0;
        for(auto it:mpp){
            if(it.second%2==1){
                cnt++;
            }
        }
        return cnt<=k;
    }
};