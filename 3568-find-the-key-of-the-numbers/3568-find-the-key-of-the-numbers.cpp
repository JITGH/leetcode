class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1=to_string(num1);
         string s2=to_string(num2);
          string s3=to_string(num3);

    s1.insert(0, 4 - s1.size(), '0');
    s2.insert(0, 4 - s2.size(), '0');
    s3.insert(0, 4 - s3.size(), '0');

    string ans="";
    for(int i=0;i<s1.size();i++){
        char mini=min({s1[i],s2[i],s3[i]});
        ans+=mini;
    }
    int result=stoi(ans);

    return result;
    }
};