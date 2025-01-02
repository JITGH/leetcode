class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        auto isvowel=[](char c){
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        int n=words.size();
        vector<int>prefix(n+1,0),ans;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+(isvowel(words[i-1].back()) && isvowel(words[i-1].front())?1:0);
        }

        for(const auto q:queries){
            ans.push_back(prefix[q[1]+1]-prefix[q[0]]);
        }
        return ans;
    }
};