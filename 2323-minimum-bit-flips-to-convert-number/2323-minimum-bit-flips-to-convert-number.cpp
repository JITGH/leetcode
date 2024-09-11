class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a=(start^goal);
        int c=0;
        int count=0;
        while(a){
            if(a&1){
                c++;
            }
            a=a>>1;
        }
        return c;
    }
};