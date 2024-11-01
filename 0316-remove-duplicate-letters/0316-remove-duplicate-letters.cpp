class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        unordered_set<char>seen;
        unordered_map<char,int>last_occ;

        for(int i=0;i<s.size();i++){
            last_occ[s[i]]=i;
        }

        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(seen.find(c)==seen.end()){
                while(!st.empty()&&c<st.top()&&i<last_occ[st.top()]){
                    seen.erase(st.top());
                    st.pop();
                }
                seen.insert(c);
                st.push(c);
            }
        }

        string result="";
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
    }
};