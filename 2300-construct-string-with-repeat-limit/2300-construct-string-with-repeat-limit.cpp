class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // vector<int>freq(26,0);
        // for(char ch:s){
        //     freq[ch-'a']++;
        // }
        // string result;
        // int currentCharInd=25;
        // while(currentCharInd>=0){
        //     if(freq[currentCharInd]==0){
        //         currentCharInd--;
        //         continue;
        //     }
        //     int use=min(freq[currentCharInd],repeatLimit);
        //     result.append(use,'a'+currentCharInd);
        //     freq[currentCharInd]-=use;

        //     if(freq[currentCharInd]>0){
        //         int smallerCharInd=currentCharInd-1;

        //         while(smallerCharInd>=0 && freq[smallerCharInd]==0){
        //         smallerCharInd--;
        //     }
        //     if(smallerCharInd<0){
        //         break;
        //     }
        //     result.push_back('a'+smallerCharInd);
        //     freq[smallerCharInd]--;
        // }
        // }
        // return result;


        map<char,int,greater<char>>mpp;
        for(char ch:s) mpp[ch]++;

        string result;
        while(!mpp.empty()){
            auto it=mpp.begin();
            char ch=it->first;
            int cnt=min(it->second,repeatLimit);

            result.append(cnt,ch);
            it->second-=cnt;
            if(it->second==0){
                mpp.erase(it);
            }
            else{
                if(mpp.size()>1){
                    auto nextit=next(mpp.begin());
                    char nextch=nextit->first;
                    int nextcnt=nextit->second;
                    result.push_back(nextch);
                if(--nextit->second==0) mpp.erase(nextit);
                }else{
                    break;
                }
            }

        }
        return result;
    }
};