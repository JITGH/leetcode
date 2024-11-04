class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        int cur=0;
        string ans="";

        while(cur<n){
            int length=0;
            char current=word[cur];

            while(cur<n && length<9 && current==word[cur]){
                length++;
                cur++;
            }
            ans+=to_string(length)+current;
        }
        return ans;
    }
};