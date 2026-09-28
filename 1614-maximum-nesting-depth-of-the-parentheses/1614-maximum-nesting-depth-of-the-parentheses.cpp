class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int max_brct=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
                cout<<"\n"<<"index -> "<<i<<" Count of ( "<<cnt<<"\n";
            }
            else if(s[i]==')'){
                max_brct=max(cnt,max_brct);
                cnt--;
            }
        }

        return max_brct;
    }
};