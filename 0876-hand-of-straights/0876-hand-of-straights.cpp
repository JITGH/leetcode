class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        unordered_map<int,int>mpp;
       
        // sort(hand.begin(),hand.end());
         for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }

       for(int card:hand){
        int sc=card;
        while(mpp[sc-1]){
            sc--;
        }

        while(sc<=card){
            while(mpp[sc]){
                for (int nextCard = sc;
                         nextCard < sc+ groupSize; nextCard++) {
                        if (!mpp[nextCard]) {
                            return false;
                        }
                        mpp[nextCard]--;
            }
        }
        sc++;
        }
       }
return true;
    }
};