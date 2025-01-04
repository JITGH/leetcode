class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>f(26,-1);
        vector<int>l(26,-1);

        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
            if(f[curr]==-1){
                f[curr]=i;
            }
            l[curr]=i;
        }

        int ans=0;
        for(int i=0;i<26;i++){
            if(f[i]==-1){
                continue;
            }

            unordered_set<char>st;
            for(int j=f[i]+1;j<l[i];j++){
                st.insert(s[j]);
            }

            ans+=st.size();
        }

        return ans;
    }
};