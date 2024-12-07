class Solution {
public:
    vector<int> diStringMatch(string s) {
        int lo=0;
        int hi=s.size();
        vector<int>ans(s.size()+1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='I') ans[i]=lo++;
            else ans[i]=hi--;
    
        }
        ans[s.size()]=lo;
        return ans;
    }

};