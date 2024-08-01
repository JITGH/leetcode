class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string str=strs[0];
        if(n==0) return "";
        for(int i=1;i<n;i++){
            while(strs[i].find(str)!=0)
                str=str.substr(0,str.size()-1);
                if(str.empty()) return"";
            
        }   
        return str;     
    }
};