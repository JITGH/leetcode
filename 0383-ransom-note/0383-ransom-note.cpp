class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        int hash[26]={0};
        for(char c:ransomNote){
            hash[c-'a']--;
        }

        for(char ch:magazine){
            hash[ch-'a']++;
        }

        for(int i=0;i<26;i++){
            if(hash[i]<0) return false;
        }

        return true;
    }
};