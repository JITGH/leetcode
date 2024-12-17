class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        string result;
        int currentCharInd=25;
        while(currentCharInd>=0){
            if(freq[currentCharInd]==0){
                currentCharInd--;
                continue;
            }
            int use=min(freq[currentCharInd],repeatLimit);
            result.append(use,'a'+currentCharInd);
            freq[currentCharInd]-=use;

            if(freq[currentCharInd]>0){
                int smallerCharInd=currentCharInd-1;

                while(smallerCharInd>=0 && freq[smallerCharInd]==0){
                smallerCharInd--;
            }
            if(smallerCharInd<0){
                break;
            }
            result.push_back('a'+smallerCharInd);
            freq[smallerCharInd]--;
        }
        }
        return result;
    }
};