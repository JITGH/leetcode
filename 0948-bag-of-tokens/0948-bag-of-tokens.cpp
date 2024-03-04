class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        while(i<=j){
            if(power>=tokens[i]){
                score+=1;
                power-=tokens[i];
                i++;
            }
            else if(i<j && score>0){
                score-=1;
                power+=tokens[j];
                j--;
            }
            else{
                return score;
            }
        }
        return score;
    }
};