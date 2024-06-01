class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=1;i<s.size();i++){
            sum=sum+abs((s[i]-'0')-(s[i-1]-'0'));
        }
        return sum;
    }
};