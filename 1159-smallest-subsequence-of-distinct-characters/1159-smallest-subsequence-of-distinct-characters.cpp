class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string ans = "";
        stack<char>st;
        vector<int>mp(26);
        vector<int>instack(26);
        for(int i=0;i<n;i++) mp[s[i]-'a']++;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>=s[i] && mp[st.top()-'a']>1 && instack[s[i]-'a']==0){
                mp[st.top()-'a']--;
                instack[st.top()-'a'] = 0;
                st.pop();
            }
            if(instack[s[i]-'a']==0) instack[s[i]-'a']=1, st.push(s[i]);
            else mp[s[i]-'a']--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};