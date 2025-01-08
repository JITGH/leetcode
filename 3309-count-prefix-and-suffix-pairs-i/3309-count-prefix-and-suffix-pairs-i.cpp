class Solution {
    private:
    bool isprefixsufixok(string& s1, string& s2){
        return s1.size()<=s2.size()&& s1==s2.substr(0,s1.size())&&s1==s2.substr(s2.size()-s1.size());
    }
public:
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
              if( isprefixsufixok(words[i],words[j])){
                c++;
              }
            }
        }
        return c++;
    }
};