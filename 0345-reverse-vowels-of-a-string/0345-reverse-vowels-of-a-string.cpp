class Solution {
public:
bool isvowel(char c){
    if(c=='a'||c=='e'||c=='o'||c=='i'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;

    return false;
}
    string reverseVowels(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            while(l<s.size() && !isvowel(s[l])){
                l++;
            }
            while(r>=0 && !isvowel(s[r])){
                r--;
            }
            if(l<r){
                swap(s[l++],s[r--]);
             
            }
            
        }
        return s;
    }
};