class Solution {
    private:
    bool isletter(char a){
        if((a>='A' && a<='Z')||(a>='a'&&a<='z')) return true;
        return false;
    }
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(isletter(s[i]) && isletter(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;

            }
            if(!isletter(s[i])||!isletter(s[j])){
                if(!isletter(s[i])) i++;
                else j--;
            }
        }
        return s;
    }
};