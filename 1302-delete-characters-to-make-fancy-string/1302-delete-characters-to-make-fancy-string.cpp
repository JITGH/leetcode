class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        int c=1;
        string str="";
        str+=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                c++;
            }else{
                c=1;
            }
            if(c<3) str+=s[i];
        }
        return str;
    }
};