class Solution {
public:
    int countSeniors(vector<string>& details) {
        //int n=details.size();
        int ct=0;
       for(auto& it:details){
        int oneage=it[11]-'0';
        int twoage=it[12]-'0';

        int age=oneage*10+twoage;

        if(age>60){
            ct++;
        }
       }
       
        return ct;
    }
};