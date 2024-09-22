class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int>hash(26,0);
        for(char c:word2){
            hash[c-'a']++;
        }

        vector<int>cnt(26,0);
        int start=0;
        int k=word2.size();
        long long c=0;

        for(int i=0;i<word1.size();i++){
            char curr=word1[i];
            if(hash[curr-'a']>0){
                if(cnt[curr-'a']<hash[curr-'a']){
                    k--;
                }
            }
            cnt[curr-'a']++;
            while(k==0){
                c+=word1.size()-i;

                char pre=word1[start];
                cnt[pre-'a']--;
                if(hash[pre-'a']>0 && cnt[pre-'a']<hash[pre-'a']){
                    k++;
                }
                start++;
            }
        }
        return c;
    }
};