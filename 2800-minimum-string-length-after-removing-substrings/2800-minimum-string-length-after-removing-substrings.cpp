class Solution {
public:
    int minLength(string s) {
       // int n=s.size();
        stack<char>st;
       // int i=0;
        for(int i=0;i<s.length();i++){
            char cur=s[i];
            if(st.empty()){
                st.push(cur);
                continue;
            }
            if(cur=='B' && st.top()=='A'){
               // cout<<st.top()<<"\n";
                st.pop();
            }
            else if(cur=='D' && st.top()=='C'){
               // cout<<st.top()<<"\n";
                st.pop();
            }else{
              //  cout<<st.top()<<"\n";
                st.push(cur);
            }
        }
        return st.size();
    }
};