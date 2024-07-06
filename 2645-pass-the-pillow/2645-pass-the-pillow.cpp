class Solution {
public:
    int passThePillow(int n, int time) {
        int fulltime=(time)/(n-1);
        int extratime=time%(n-1);
        int ans=0;
        if(fulltime%2==0){
            ans=extratime+1;
        }
        else{
            ans=n-extratime;
        }
        return ans;
    }
};