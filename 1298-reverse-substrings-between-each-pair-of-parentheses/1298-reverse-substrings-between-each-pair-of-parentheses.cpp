class Solution {
public:
    string reverseParentheses(string s) {
        //take a stack
        stack<int>st;
        //store the length of s
        string result;
        for(char it:s){
            if(it=='('){
                //push the length of that string
                st.push(result.length());
            }else if(it==')'){
                //pop out and revese that string 
                int start=st.top();
                st.pop();
                reverse(result.begin()+start,result.end());
            }else{
                result+=it;
            }
        }
        return result;
    }
};