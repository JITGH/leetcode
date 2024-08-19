class Solution {
    private:
    int step(int curlen,int pastelen,int n){
        if(curlen==n) return 0;
        if(curlen>n) return 1000;
        int op1=2+step(curlen*2,curlen,n);
        int op2=1+step(curlen+pastelen,pastelen,n);
        return min(op1,op2);
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        return 1+step(1,1,n);
    }
};