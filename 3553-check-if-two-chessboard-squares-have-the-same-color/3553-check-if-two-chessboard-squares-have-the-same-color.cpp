class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
      int r1=c1[0]-'a'+1;
      int co1=c1[1]-'0';
       int r2=c2[0]-'a'+1;
       int co2=c2[1]-'0';


       return ((r1+co1)%2==(r2+co2)%2);
    }
};