class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum=0;
        map<int,int>mpp;
        while(n>0){
            int r=n%10;
            mpp[r]++;
            n=n/10;
        }
    

    for(const auto &it:mpp){
        int num=it.first;
        int cnt=it.second;
        //sum+=it.first()*(it.second());
        sum+=num*cnt;
    }

return sum;
    }
};