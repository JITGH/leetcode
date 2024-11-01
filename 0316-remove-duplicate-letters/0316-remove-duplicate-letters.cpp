// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         stack<char>st;
//         unordered_set<char>seen;
//         unordered_map<char,int>last_occ;

//         for(int i=0;i<s.size();i++){
//             last_occ[s[i]]=i;
//         }

//         for(int i=0;i<s.size();i++){
//             char c=s[i];
//             if(seen.find(c)==seen.end()){
//                 while(!st.empty()&&c<st.top()&&i<last_occ[st.top()]){
//                     seen.erase(st.top());
//                     st.pop();
//                 }
//                 seen.insert(c);
//                 st.push(c);
//             }
//         }

//         string result="";
//         while(!st.empty()){
//             result=st.top()+result;
//             st.pop();
//         }
//         return result;
//     }
// };

class Solution {
public:
    string removeDuplicateLetters(string s) {
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