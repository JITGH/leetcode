class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int cz=0;
            int co=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='0') cz++;
                if(s[j]=='1') co++;

                if(cz<=k || co<=k){
                    ans++;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};