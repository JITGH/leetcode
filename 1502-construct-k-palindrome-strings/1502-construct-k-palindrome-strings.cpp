class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        if(s.size()==k) return true;
       // unordered_map<char,int>mpp;
       vector<int>hash(26,0);
        for(int i=0;i<s.size();i++){
           // mpp[s[i]]++;
           hash[s[i]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(hash[i]%2==1){
                cnt++;
            }
        }
        return cnt<=k;
    }
};