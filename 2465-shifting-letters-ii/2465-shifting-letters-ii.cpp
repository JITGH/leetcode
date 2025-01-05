class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n+1,0);
        for(auto &shift:shifts){
            
            diff[shift[0]]+=(shift[2]==0)?-1:1;
           if(shift[1]+1<n) diff[shift[1]+1]+=(shift[2]==0)?1:-1;
        }

        int shiftsum=0;
       // string ans="";
        for(int i=0;i<n;i++){
           // cout<<diff[i]<<"\n";
            shiftsum=(shiftsum+diff[i])%26;
            if(shiftsum<0) shiftsum+=26;

          s[i]='a'+(s[i] - 'a' + shiftsum) % 26;
           
        }

        return s;
    }
};