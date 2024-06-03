class Solution {
public:
    int appendCharacters(string s, string t) {
        int c=0;
        int i=0;
        int j=0;

        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]) j++;

            i++;
        }
        return t.length()-j;
    }
};