class Solution {
public:
    bool isvowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;

        return false;
    }

    int maxFreqSum(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int vc=0;
        int cc=0;
        for(auto it:mpp){
            if(isvowel(it.first)){
                vc=max(vc,it.second);
            }
            else cc=max(cc,it.second);
        }

        return vc+cc;
    }
};