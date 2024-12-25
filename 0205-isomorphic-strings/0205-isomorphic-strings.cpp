class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // unordered_map<int,int>st,ts;
        // for(int i=0;i<s.size();i++){
        //     if((st[s[i]] && st[s[i]]!=t[i])or(ts[t[i]] && ts[t[i]]!=s[i])){
        //         return false;
        //     }
        //     st[s[i]]=t[i];
        //     ts[t[i]]=s[i];
        // }
        // return true;


if (s.length() != t.length()) return false;

    char mappedST[256] = {0};
    char mappedTS[256] = {0};

    for (int i = 0; i < s.length(); ++i) {
        char sChar = s[i];
        char tChar = t[i];

        // Check two-way mappings
        if (mappedST[sChar] == 0 && mappedTS[tChar] == 0) {
            mappedST[sChar] = tChar;
            mappedTS[tChar] = sChar;
        } 
        else if (mappedST[sChar] != tChar || mappedTS[tChar] != sChar) {
            return false;
        }
    }

    return true;
    }
};