class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;
        int cnt=0;
        for(char c:s){
            mpp[c]++;
            
            if((mpp[c]%2)==1){
                cnt++;
            }else{
                cnt--;
            }
        }
        
        if(cnt>0){
            return s.length()- cnt + 1;
        }
        else{
            return s.length();
        }
        
    }
};