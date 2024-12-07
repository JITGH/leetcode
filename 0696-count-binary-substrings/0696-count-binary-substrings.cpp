class Solution {
public:
    int countBinarySubstrings(string s) {
       // vector<int>group(s.size());
        int prev=0;
        int t=0;
        int cur=1;
         int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]){
              //  group[++t]=1;
                ans+=min(prev,cur);
                prev=cur;
                cur=1;
            }else{
                cur++;
            }
        }
       
        //for(int i=1;i<=t;i++){
            ans+=min(prev,cur);
       // }
        return ans;
    }
};