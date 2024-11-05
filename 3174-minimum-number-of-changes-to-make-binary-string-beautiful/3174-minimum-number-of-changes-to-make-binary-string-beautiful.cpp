class Solution {
public:
    int minChanges(string s) {
        // int cnt=0;
        // for(int i=0;i<s.size();i+=2){
        //     if(s[i]!=s[i+1]) cnt++;
        // }
        // return cnt;

        char current=s[0];
        int minchange=0;
        int cons=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==current){
                cons++;
                continue;
            }if(cons%2==0){
                cons=1;
            }else{
                cons=0;
                minchange+=1;
            }
            current=s[i];
        }
        return minchange;
    }
};