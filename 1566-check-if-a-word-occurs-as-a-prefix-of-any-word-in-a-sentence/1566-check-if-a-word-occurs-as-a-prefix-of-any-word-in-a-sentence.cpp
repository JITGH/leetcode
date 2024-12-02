class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int cur=1;
        int ind=0;
        int l=sentence.length();
        while(ind<l){
            while(ind<l && sentence[ind]==' '){
                ind++;
                cur++;
            }

            int match=0;
            while(ind<l && match<searchWord.length()&&sentence[ind]==searchWord[match]){
                ind++;
                match++;
            }
            if(match==searchWord.length()){
                return cur;
            }
            while(ind<l && sentence[ind]!=' '){
                ind++;
            }
        }
        return -1;
    }
};